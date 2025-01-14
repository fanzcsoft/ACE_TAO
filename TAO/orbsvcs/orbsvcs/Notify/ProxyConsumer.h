// -*- C++ -*-

/**
 *  @file ProxyConsumer.h
 *
 *  @author Pradeep Gore <pradeep@oomworks.com>
 */

#ifndef TAO_Notify_PROXYCONSUMER_H
#define TAO_Notify_PROXYCONSUMER_H

#include /**/ "ace/pre.h"

#include "orbsvcs/Notify/notify_serv_export.h"
#include "orbsvcs/Notify/Event.h"
#include "orbsvcs/Notify/Proxy.h"
#include "orbsvcs/Notify/SupplierAdmin.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "orbsvcs/CosEventChannelAdminC.h"

#include "ace/Auto_Ptr.h"

TAO_BEGIN_VERSIONED_NAMESPACE_DECL

class TAO_Notify_Supplier;

/**
 * @class TAO_Notify_ProxyConsumer
 *
 * @brief Base class for all types of ProxyConsumer implementations.
 */
class TAO_Notify_Serv_Export TAO_Notify_ProxyConsumer
  : public virtual TAO_Notify_Proxy
{
public:
  typedef TAO_Notify_Refcountable_Guard_T<TAO_Notify_ProxyConsumer> Ptr;
  /// Constructor
  TAO_Notify_ProxyConsumer ();

  /// Destructor
  virtual ~TAO_Notify_ProxyConsumer ();

  /// init: overrides Topology_Object method
  virtual void init (TAO_Notify::Topology_Parent * topology_parent);

  /// Connect
  void connect (TAO_Notify_Supplier* supplier);

  /// Disconnect
  void disconnect ();

  /// Shutdown  (TAO_Notify_Container_T method)
  virtual int shutdown ();

  /// Destroy this object.
  virtual void destroy ();

  /// Return true if connected
  bool is_connected () const;

  /// The SA parent.
  TAO_Notify_SupplierAdmin& supplier_admin ();

  ACE_Time_Value last_ping() const;
  void last_ping(const ACE_Time_Value& tv);

protected:
  /// Access the Supplier
  TAO_Notify_Supplier* supplier ();

  /// Accept an event from the Supplier
  void push_i (TAO_Notify_Event * event);

  /// Last time either push an event or validate connection
  /// via _non_exist call.
  ACE_Atomic_Op<TAO_SYNCH_MUTEX, ACE_Time_Value> last_ping_;

private:
  /// Is this part of a reliable channel
  bool supports_reliable_events () const;

  ///= Data Members.
  /// The SA parent.
  TAO_Notify_SupplierAdmin::Ptr supplier_admin_;

  /// The Supplier that we're connect to.
  ACE_Auto_Ptr<TAO_Notify_Supplier> supplier_;

  /// Access our Peer.
  virtual TAO_Notify_Peer* peer ();
};

TAO_END_VERSIONED_NAMESPACE_DECL

#if defined (__ACE_INLINE__)
#include "orbsvcs/Notify/ProxyConsumer.inl"
#endif /* __ACE_INLINE__ */

#include /**/ "ace/post.h"
#endif /* TAO_Notify_PROXYCONSUMER_H */
