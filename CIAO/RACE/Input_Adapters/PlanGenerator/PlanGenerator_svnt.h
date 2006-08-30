// $Id$
//
// ****              Code generated by the                 ****
// ****  Component Integrated ACE ORB (CIAO) CIDL Compiler ****
// CIAO has been developed by:
//       Center for Distributed Object Computing
//       Washington University
//       St. Louis, MO
//       USA
//       http://www.cs.wustl.edu/~schmidt/doc-center.html
// CIDL Compiler has been developed by:
//       Institute for Software Integrated Systems
//       Vanderbilt University
//       Nashville, TN
//       USA
//       http://www.isis.vanderbilt.edu/
//
// Information about CIAO is available at:
//    http://www.dre.vanderbilt.edu/CIAO

#ifndef CIAO_GLUE_SESSION_PLANGENERATOR_SVNT_H
#define CIAO_GLUE_SESSION_PLANGENERATOR_SVNT_H

#include /**/ "ace/pre.h"

#include "PlanGeneratorEC.h"

#if !defined (ACE_LACKS_PRAGMA_ONCE)
# pragma once
#endif /* ACE_LACKS_PRAGMA_ONCE */

#include "ciao/Container_Base.h"
#include "ciao/Context_Impl_T.h"
#include "ciao/Servant_Impl_T.h"
#include "ciao/Home_Servant_Impl_T.h"

#include "PlanGeneratorS.h"

namespace CIAO
{
  namespace RACE
  {
    namespace CIDL_PlanGenerator_Impl
    {
      class PlanGenerator_Servant;

      class PLANGENERATOR_SVNT_Export PlanGenerator_Context
        : public virtual CIAO::Context_Impl<
            ::CIAO::RACE::CCM_PlanGenerator_Context,
            PlanGenerator_Servant,
            ::CIAO::RACE::PlanGenerator,
            ::CIAO::RACE::PlanGenerator_var
          >
      {
        public:
        // We will allow the servant glue code we generate to access our state.
        friend class PlanGenerator_Servant;

        PlanGenerator_Context (
          ::Components::CCMHome_ptr h,
          ::CIAO::Session_Container *c,
          PlanGenerator_Servant *sv);

        virtual ~PlanGenerator_Context (void);

        // Operations for PlanGenerator receptacles and event sources,
        // defined in ::CIAO::RACE::CCM_PlanGenerator_Context.

        virtual ::CIAO::RACE::PlanIngress_ptr
        get_connection_ingress (
          ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC (( ::CORBA::SystemException));

        // CIAO-specific.

        static PlanGenerator_Context *
        _narrow (
          ::Components::SessionContext_ptr p
          ACE_ENV_ARG_DECL_WITH_DEFAULTS);

        protected:
        // Methods that manage this component's connections and consumers.

        virtual void
        connect_ingress (
          ::CIAO::RACE::PlanIngress_ptr
          ACE_ENV_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC (( ::CORBA::SystemException,
                         ::Components::AlreadyConnected,
                         ::Components::InvalidConnection));

        virtual ::CIAO::RACE::PlanIngress_ptr
        disconnect_ingress (
          ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC (( ::CORBA::SystemException,
                         ::Components::NoConnection));

        protected:
        // Simplex ingress connection.
        ::CIAO::RACE::PlanIngress_var
        ciao_uses_ingress_;
      };

      class PLANGENERATOR_SVNT_Export PlanGenerator_Servant
        : public virtual CIAO::Servant_Impl<
            POA_CIAO::RACE::PlanGenerator,
            ::CIAO::RACE::CCM_PlanGenerator,
            PlanGenerator_Context
          >
      {
        public:

        typedef ::CIAO::RACE::CCM_PlanGenerator _exec_type;

        PlanGenerator_Servant (
          ::CIAO::RACE::CCM_PlanGenerator_ptr executor,
          ::Components::CCMHome_ptr h,
          const char *ins_name,
          ::CIAO::Home_Servant_Impl_Base *hs,
          ::CIAO::Session_Container *c,
          ::CIAO::REC_POL_MAP &rec_pol_map);

        virtual ~PlanGenerator_Servant (void);

        virtual void
        set_attributes (
          const ::Components::ConfigValues &descr
          ACE_ENV_ARG_DECL);

        // Supported operations.

        // Public port operations.

        virtual void
        connect_ingress (
          ::CIAO::RACE::PlanIngress_ptr c
          ACE_ENV_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC (( ::CORBA::SystemException,
                         ::Components::AlreadyConnected,
                         ::Components::InvalidConnection));

        virtual ::CIAO::RACE::PlanIngress_ptr
        disconnect_ingress (
          ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC (( ::CORBA::SystemException,
                         ::Components::NoConnection));

        virtual ::CIAO::RACE::PlanIngress_ptr
        get_connection_ingress (
          ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC (( ::CORBA::SystemException));

        // Servant class for the deployment consumer.
        class PLANGENERATOR_SVNT_Export Deploy_InputConsumer_deployment_Servant
        : public virtual POA_CIAO::RACE::Deploy_InputConsumer
        {
          public:
          Deploy_InputConsumer_deployment_Servant (
            ::CIAO::RACE::CCM_PlanGenerator_ptr executor,
            ::CIAO::RACE::CCM_PlanGenerator_Context_ptr c);

          virtual ~Deploy_InputConsumer_deployment_Servant (void);

          virtual void
          push_Deploy_Input (
            ::CIAO::RACE::Deploy_Input *evt
            ACE_ENV_ARG_DECL_WITH_DEFAULTS)
          ACE_THROW_SPEC (( ::CORBA::SystemException));

          // Inherited from ::Components::EventConsumerBase.
          virtual void
          push_event ( ::Components::EventBase *ev
                      ACE_ENV_ARG_DECL_WITH_DEFAULTS)
          ACE_THROW_SPEC (( ::CORBA::SystemException,
                           ::Components::BadEventType));

          // CIAO-specific in ::Components::EventConsumerBase.
          virtual CORBA::Boolean
          ciao_is_substitutable (
            const char *event_repo_id
            ACE_ENV_ARG_DECL_WITH_DEFAULTS)
          ACE_THROW_SPEC (( ::CORBA::SystemException));

          // Get component implementation.
          virtual CORBA::Object_ptr
          _get_component (
            ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
          ACE_THROW_SPEC (( ::CORBA::SystemException));

          protected:
          ::CIAO::RACE::CCM_PlanGenerator_var
          executor_;

          ::CIAO::RACE::CCM_PlanGenerator_Context_var
          ctx_;
        };

        virtual ::CIAO::RACE::Deploy_InputConsumer_ptr
        get_consumer_deployment (
          ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC (( ::CORBA::SystemException));

        // Component attribute operations.

        // Operations for Receptacles interface.

        virtual ::Components::Cookie *
        connect (
          const char *name,
          CORBA::Object_ptr connection
          ACE_ENV_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC (( ::CORBA::SystemException,
                         ::Components::InvalidName,
                         ::Components::InvalidConnection,
                         ::Components::AlreadyConnected,
                         ::Components::ExceededConnectionLimit));

        virtual CORBA::Object_ptr
        disconnect (
          const char *name,
          ::Components::Cookie *ck
          ACE_ENV_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC (( ::CORBA::SystemException,
                         ::Components::InvalidName,
                         ::Components::InvalidConnection,
                         ::Components::CookieRequired,
                         ::Components::NoConnection));

        virtual ::Components::ReceptacleDescriptions *
        get_all_receptacles (
          ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC (( ::CORBA::SystemException));

        // Operations for Events interface.

        virtual ::Components::Cookie *
        subscribe (
          const char *publisher_name,
          ::Components::EventConsumerBase_ptr subscriber
          ACE_ENV_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC (( ::CORBA::SystemException,
                         ::Components::InvalidName,
                         ::Components::InvalidConnection,
                         ::Components::ExceededConnectionLimit));

        virtual ::Components::EventConsumerBase_ptr
        unsubscribe (
          const char *publisher_name,
          ::Components::Cookie *ck
          ACE_ENV_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC (( ::CORBA::SystemException,
                         ::Components::InvalidName,
                         ::Components::InvalidConnection));

        virtual void
        connect_consumer (
          const char *emitter_name,
          ::Components::EventConsumerBase_ptr consumer
          ACE_ENV_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC (( ::CORBA::SystemException,
                         ::Components::InvalidName,
                         ::Components::AlreadyConnected,
                         ::Components::InvalidConnection));

        virtual ::Components::EventConsumerBase_ptr
        disconnect_consumer (
          const char *source_name
          ACE_ENV_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC (( ::CORBA::SystemException,
                         ::Components::InvalidName,
                         ::Components::NoConnection));

        virtual ::Components::PublisherDescriptions *
        get_all_publishers (
          ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC (( ::CORBA::SystemException));

        virtual ::Components::EmitterDescriptions *
        get_all_emitters (
          ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC (( ::CORBA::SystemException));

        // CIAO specific operations on the servant. 
        CORBA::Object_ptr
        get_facet_executor (
          const char *name
          ACE_ENV_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC (( ::CORBA::SystemException));

        private:

        ::CIAO::RACE::Deploy_InputConsumer_var
        consumes_deployment_;

        const char *ins_name_;

        private:

        void
        populate_port_tables (
          ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC (( ::CORBA::SystemException));

        ::Components::EventConsumerBase_ptr
        get_consumer_deployment_i (
          ACE_ENV_SINGLE_ARG_DECL_WITH_DEFAULTS)
        ACE_THROW_SPEC (( ::CORBA::SystemException));
      };

      class PLANGENERATOR_SVNT_Export PlanGenerator_Home_Servant
        : public virtual
            ::CIAO::Home_Servant_Impl<
                ::POA_CIAO::RACE::PlanGenerator_Home,
                ::CIAO::RACE::CCM_PlanGenerator_Home,
                PlanGenerator_Servant
              >
      {
        public:

        PlanGenerator_Home_Servant (
          ::CIAO::RACE::CCM_PlanGenerator_Home_ptr exe,
          const char *ins_name,
          ::CIAO::Session_Container *c,
          ::CIAO::REC_POL_MAP &rec_pol_map);

        virtual ~PlanGenerator_Home_Servant (void);

        // Home operations.
        // Home factory and finder operations.

        // Attribute operations.
      };

      extern "C" PLANGENERATOR_SVNT_Export ::PortableServer::Servant
      create_CIAO_RACE_PlanGenerator_Home_Servant (
        ::Components::HomeExecutorBase_ptr p,
        CIAO::Session_Container *c,
        const char *ins_name,
        ::CIAO::REC_POL_MAP &rec_pol_map
        ACE_ENV_ARG_DECL_WITH_DEFAULTS);
    }
  }
}

#include /**/ "ace/post.h"

#endif /* CIAO_GLUE_SESSION_PLANGENERATOR_SVNT_H */

