#ifndef MOOSE_EXP01APP_H
#define MOOSE_EXP01APP_H

#include "MooseApp.h"

class MooseExp01App;

template<>
InputParameters validParams<MooseExp01App>();

class MooseExp01App : public MooseApp
{
public:
  MooseExp01App(InputParameters parameters);
  virtual ~MooseExp01App();

  static void registerApps();
  static void registerObjects(Factory & factory);
  static void associateSyntax(Syntax & syntax, ActionFactory & action_factory);
};

#endif /* MOOSE_EXP01APP_H */
