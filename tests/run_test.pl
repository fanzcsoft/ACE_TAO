eval '(exit $?0)' && eval 'exec perl -S $0 ${1+"$@"}'
    & eval 'exec perl -S $0 $argv:q'
    if 0;

# $Id$
# -*- perl -*-
# This file is for running the tests in the ACE tests directory.

unshift @INC, '../bin';
require ACEutils;

use Cwd;
use English;
use Getopt::Std;

if (!getopts ('tc:') || $opt_h) {
    print "run_test.pl [-h] [-c config] [-t] [file1 file2 ...]\n";
    print "\n";
    print "Runs the tests listed in run_test.lst\n";
    print "\n";
    print "Options:\n";
    print "    -c config  Run the tests for the <config> platform\n";
    print "    -h         display this help\n";
    print "    -t         Runs all the tests passed via the cmd line\n";
    print "\n";
    print "Configs: MSVC\n";
    exit (1);
}

if ($OSNAME eq 'MSWin32') {
    $config = 'MSVC';
}

if ($opt_c) {
    $config = $opt_c;
}
else {
    print "Defaulting to configuration: $config\n";
}

if (!($ACE_ROOT = $ENV{ACE_ROOT})) {
    my $cd = getcwd ();
    chdir ('..');
    $ACE_ROOT = getcwd ().$DIR_SEPARATOR;
    chdir ($cd);
    warn "ACE_ROOT not defined, defaulting to ACE_ROOT=$ACE_ROOT";
}

if (!($tmp = $ENV{TMP})) {
  $tmp="/tmp";
}

################################################################################

@tests = ();

# Loads the list and runs it
sub read_run_test_list ()
{
    my $line;
    open (LIST, "<run_test.lst") 
        || die "Cannot open run_test.lst";

    while (<LIST>) {
        next if (/^#/ || /^\s*$/);  # ignore comments and blank lines

        chomp;
        my @stuff = split ":";

        if (!/$config/) {
            my $program = shift @stuff;
            $program =~ s/\s*//g;  #remove any extra whitepace
            push @tests, $program;
        }
    }   

    close (LIST);
}

sub run_program ($)
{
    my $program = shift;

    $program_exe = $EXEPREFIX.$program.$EXE_EXT;

    unlink "core";
    local $log = "log/".$program.".log";
    unlink $log;

    ### Try to run the program

    if (! -x $program_exe) {
        print STDERR "Error: $program_exe does not exist\n";
        return;
    }

    print STDERR "Running $program\n";
    $P = Process::Create ($program_exe, "");
    $status = $P->TimedWait (300);

    if ($status == -1) {
        print STDERR "Error: $program FAILED (time out)\n";
        $P->Kill (); $P->TimedWait (1);
    } elsif ($status != 0) {
        print STDERR "Error: $program FAILED with exit status $status\n";
    }

    check_log ($log);
}

sub check_log ($)
{
    my $log = shift;
    ### Check the logs
    if (-e "core") {
        print STDERR "$program dumped core!!!!\n";
    }
    if (! -e $log ) {
        print STDERR "Error: No log file ($log) is present\n";
    } else {
        if (open (LOG, "<". $log) == 0) {
            print STDERR "Error: Cannot open log file $log\n";
        } else {
            my $starting_matched = 0;
            my $ending_matched = 0;
            my $bad_matched = 0;
            
            while (<LOG>) {
                chomp;
                
                if (m/Starting/) {
                    $starting_matched = 1;
                }
                
                if (m/Ending/) {
                    $ending_matched = 1;
                }
        
                if (m/assertion failed|timeout|Bad file number/) {
                    $bad_matched = 1;
                }
        
                if ($log =~ /Cached_Accept_Conn_Test/
                    && m/No such file or directory/) {
                    $bad_matched = 1;
                }
                
                if (m/not supported/) {
                    print STDERR "Error: ($log): $_\n";
                }
            }

            close (LOG); # ignore errors

            if ($starting_matched == 0) {
                print STDERR "Error ($log): no line with 'starting'\n";
            }
            
            if ($ending_matched == 0) {
                print STDERR "Error ($log): no line with 'Ending'\n";
            }
      
            if ($bad_matched == 1) {
                print STDERR "Error ($log): unexpected output\n";
            }
      
        }
    }
}

sub delete_temp_files ()
{
    unlink "ace_pipe_name";
    unlink "pattern";

    if (!opendir (DIR, $tmp)) {
        warn "Cannot open temp directory $tmp\n";
        return;
    }

    my @files =readdir (DIR);
    closedir (DIR);

    my $file = "";
    foreach $file (@files) {
      if ($file =~ /^ace_temp_file/
          || $file =~ /^Naming_Test/) 
      {
          unlink $tmp.$DIR_SEPARATOR.$file;
      }
    }
}

################################################################################

if (!$opt_t) {
    read_run_test_list ();
} 
else {
    @tests = @ARGV;
}

foreach $test (@tests) {
  run_program ($test);
}

delete_temp_files ();

exit ();

