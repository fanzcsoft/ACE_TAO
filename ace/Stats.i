/* -*- C++ -*- */
// $Id$

ACE_INLINE
ACE_Stats_Value::ACE_Stats_Value (const u_int precision)
  : whole_ (0),
    fractional_ (0),
    precision_ (precision)
{
}

ACE_INLINE
u_int
ACE_Stats_Value::precision (void) const
{
  return precision_;
}

ACE_INLINE
void
ACE_Stats_Value::whole (const ACE_UINT32 value)
{
  whole_ = value;
}

ACE_INLINE
ACE_UINT32
ACE_Stats_Value::whole (void) const
{
  return whole_;
}

ACE_INLINE
void
ACE_Stats_Value::fractional (const ACE_UINT32 value)
{
  fractional_ = value;
}

ACE_INLINE
ACE_UINT32
ACE_Stats_Value::fractional (void) const
{
  return fractional_;
}

ACE_INLINE
void
ACE_Stats_Value::scaled_value (ACE_UINT64 &sv) const
{
  sv = whole () * fractional_field ()  +  fractional ();
}

ACE_INLINE
void
ACE_Stats_Value::dump (void) const
{
  ACE_DEBUG ((LM_DEBUG,
              ASYS_TEXT ("precision: %u digits; whole: %u, fractional: %u\n"),
              precision_, whole_, fractional_);
}

ACE_INLINE
ACE_Stats::ACE_Stats (void)
{
  reset ();
}

ACE_INLINE
ACE_UINT32
ACE_Stats::samples (void) const
{
  return number_of_samples_;
}

ACE_INLINE
ACE_INT32
ACE_Stats::min_value (void) const
{
  return min_;
}

ACE_INLINE
ACE_INT32
ACE_Stats::max_value (void) const
{
  return max_;
}

ACE_INLINE
void
ACE_Stats::dump (void) const
{
  print_summary (3u);
}
