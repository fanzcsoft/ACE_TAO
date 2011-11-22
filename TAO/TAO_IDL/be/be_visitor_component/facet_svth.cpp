
//=============================================================================
/**
 *  @file    facet_svh.cpp
 *
 *  $Id$
 *
 *  Visitor generating code for a facet servant class in the
 *  servant header.
 *
 *
 *  @author Jeff Parsons
 */
//=============================================================================

be_visitor_facet_svth::be_visitor_facet_svth (be_visitor_context *ctx)
  : be_visitor_component_scope (ctx)
{
}

be_visitor_facet_svth::~be_visitor_facet_svth (void)
{
}

int
be_visitor_facet_svth::visit_provides (be_provides *node)
{
  if (node->gen_facet_svnt_tmpl_decl (os_) == -1)
    {
      ACE_ERROR_RETURN ((LM_ERROR,
                         ACE_TEXT ("be_visitor_facet_svth")
                         ACE_TEXT ("::visit_provides - ")
                         ACE_TEXT ("gen_facet_svnt_decl() ")
                         ACE_TEXT ("failed\n")),
                        -1);
    }
}

int
be_visitor_facet_svth::visit_component (be_component *node)
{
  this->visit_component_scope (node);

  return 0;
}

