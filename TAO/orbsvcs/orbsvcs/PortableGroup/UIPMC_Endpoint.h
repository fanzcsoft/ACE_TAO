// -*- C++ -*-

//=============================================================================
/**
 *  @file     UIPMC_Endpoint.h
 *
 *  UIPMC implementation of PP Framework Endpoint interface.
 *
 *  @author Frank Hunleth <fhunleth@cs.wustl.edu>
 */
//=============================================================================

#ifndef TAO_UIPMC_ENDPOINT_H
#define TAO_UIPMC_ENDPOINT_H

#include /**/ "ace/pre.h"

#include "tao/Endpoint.h"
#include "tao/IIOP_Endpoint.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "tao/CORBA_String.h"
#include "ace/INET_Addr.h"

#include "orbsvcs/PortableGroup/portablegroup_export.h"

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

/**
 * @class TAO_UIPMC_Endpoint
 *
 * @brief TAO_UIPMC_Endpoint
 *
 * UIPMC-specific implementation of PP Framework Endpoint interface.
 */
class TAO_PortableGroup_Export TAO_UIPMC_Endpoint : public TAO_Endpoint
{
public:
  /// Default constructor.
  TAO_UIPMC_Endpoint ();

  /// Constructor.
  TAO_UIPMC_Endpoint (const ACE_INET_Addr &addr);

  /// Constructor. @@ Frank - deprecate this.
  TAO_UIPMC_Endpoint (const CORBA::Octet class_d_address[4],
                      CORBA::UShort port);

  /// Destructor.
  ~TAO_UIPMC_Endpoint ();

  // = Implementation of abstract TAO_Endpoint methods.  See
  // Endpoint.h for their documentation.

  virtual TAO_Endpoint *next ();
  virtual int addr_to_string (char *buffer, size_t length);

  /// Makes a copy of this TAO_Endpoint.
  virtual TAO_Endpoint *duplicate ();

  /// Return true if this endpoint is equivalent to @a other_endpoint.  Two
  /// endpoints are equivalent if their port and host are the same.
  CORBA::Boolean is_equivalent (const TAO_Endpoint *other_endpoint);

  /// Return a hash value for this object.
  CORBA::ULong hash ();

  // Allocates memory and returns a copy of <this>

  // = UIPMC_Endpoint-specific methods.

  /// Return a reference to the  object_addr .
  const ACE_INET_Addr &object_addr () const;

  /// Set the IP multicast address and port.
  void object_addr (const ACE_INET_Addr &addr);

  /// Return a pointer to the stringified host address (not including the
  /// port).  This class retains ownership of the address memory.
  const char *host () const;

  /// Return the port number.
  CORBA::UShort port () const;

  /// Set the port number.
  CORBA::UShort port (CORBA::UShort p); //@@ Frank - deprecate this.

  //TAO_UIPMC_Connection_Handler *&hint ();
  // Access to our <hint_>.
  /// Do we have a preferred local network interface set for this target?
  bool is_preferred_network () const;

  /// Return the preferred network interface if any.
  const char *preferred_network () const;

  /// Transform this endpoint into (potentially) a chain of endpoints
  /// in preferrence order of specific local interface bind address (if
  /// the ORB is thus configured)
  CORBA::ULong preferred_interfaces (TAO_ORB_Core *oc);

  /// Acessor for the preferred network interface name if set
  const char *preferred_if () const;

private:
  /// Helper methods for getting and setting the IP address.  @@ Vadym - deprecate these.
  ACE_UINT32 uint_ip_addr () const;
  void uint_ip_addr (ACE_UINT32 ip_addr);

  /// Helper method to update the cached object address.  @@ Vadym - deprecate this.
  void update_object_addr ();

  /// IP Multicast address.  @@ Frank - deprecate this.
  CORBA::Octet class_d_address_[4];

  /// String representing the host address.
  CORBA::String_var host_;

  /// UDP port number.
  CORBA::UShort port_;

  /// Cached instance of ACE_INET_Addr for use in making
  /// invocations, etc.
  ACE_INET_Addr object_addr_;

  /// Preferred path for routing this endpoint.
  TAO::IIOP_Endpoint_Info preferred_path_;

  /// UIPMC Endpoints can be strung into a list.  Return the next
  /// endpoint in the list, if any.
  TAO_UIPMC_Endpoint *next_;

  /// Preferred interface name (if set)
  CORBA::String_var preferred_if_;
};

TAO_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
# include "orbsvcs/PortableGroup/UIPMC_Endpoint.inl"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"

#endif  /* TAO_UIPMC_PROFILE_H */
