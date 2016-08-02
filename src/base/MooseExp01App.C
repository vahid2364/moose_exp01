#include "MooseExp01App.h"
#include "Moose.h"
#include "AppFactory.h"
#include "ModulesApp.h"
#include "MooseSyntax.h"

template<>
InputParameters validParams<MooseExp01App>()
{
  InputParameters params = validParams<MooseApp>();

  params.set<bool>("use_legacy_uo_initialization") = false;
  params.set<bool>("use_legacy_uo_aux_computation") = false;
  params.set<bool>("use_legacy_output_syntax") = false;

  return params;
}

MooseExp01App::MooseExp01App(InputParameters parameters) :
    MooseApp(parameters)
{
  Moose::registerObjects(_factory);
  ModulesApp::registerObjects(_factory);
  MooseExp01App::registerObjects(_factory);

  Moose::associateSyntax(_syntax, _action_factory);
  ModulesApp::associateSyntax(_syntax, _action_factory);
  MooseExp01App::associateSyntax(_syntax, _action_factory);
}

MooseExp01App::~MooseExp01App()
{
}

// External entry point for dynamic application loading
extern "C" void MooseExp01App__registerApps() { MooseExp01App::registerApps(); }
void
MooseExp01App::registerApps()
{
  registerApp(MooseExp01App);
}

// External entry point for dynamic object registration
extern "C" void MooseExp01App__registerObjects(Factory & factory) { MooseExp01App::registerObjects(factory); }
void
MooseExp01App::registerObjects(Factory & factory)
{
}

// External entry point for dynamic syntax association
extern "C" void MooseExp01App__associateSyntax(Syntax & syntax, ActionFactory & action_factory) { MooseExp01App::associateSyntax(syntax, action_factory); }
void
MooseExp01App::associateSyntax(Syntax & /*syntax*/, ActionFactory & /*action_factory*/)
{
}
