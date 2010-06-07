// $Id$

#include "Client_ORBInitializer.h"
#include "client_interceptor.h"


ACE_RCSID (Service_Context_Manipulation, Client_ORBInitializer, "$Id$")

Client_ORBInitializer::Client_ORBInitializer ()
{ 

}

void
Client_ORBInitializer::pre_init (
    PortableInterceptor::ORBInitInfo_ptr info)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
}

void
Client_ORBInitializer::post_init (
    PortableInterceptor::ORBInitInfo_ptr info)
  ACE_THROW_SPEC ((CORBA::SystemException))
{
  PortableInterceptor::ClientRequestInterceptor_ptr interceptor =
    PortableInterceptor::ClientRequestInterceptor::_nil ();

  // Install the Echo client request interceptor
  ACE_NEW_THROW_EX (interceptor,
                    Echo_Client_Request_Interceptor (),
                    CORBA::NO_MEMORY ());

  PortableInterceptor::ClientRequestInterceptor_var
    client_interceptor = interceptor;

  info->add_client_request_interceptor (client_interceptor.in ());
}

