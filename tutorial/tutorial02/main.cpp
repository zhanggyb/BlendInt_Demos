/**
 * BlendInt demo
 */

#include <iostream>
#include <cassert>

#include <blendint/gui/window.hpp>
#include <blendint/gui/message-box.hpp>
#include <event/event.hpp>

class TestClassBase
{
public:

  TestClassBase ()
  {
  }

  virtual ~TestClassBase ()
  {
  }

  virtual void Method0 ()
  {
    std::cout << "Method0 in base class" << std::endl;
  }

  virtual void Method1 (int p0)
  {
    std::cout << "Method1 in base class, param0: " << p0 << std::endl;
  }

  virtual void Method2 (int p0, int p1) const
  {
    std::cout << "const Method2 in base class, param0: " << p0 << " param1: " << p1
        << std::endl;
  }

};

class TestClassDerived: public TestClassBase
{
public:

  TestClassDerived ()
      : TestClassBase()
  {
  }

  virtual ~TestClassDerived ()
  {

  }

  virtual void Method0 () override
  {
    std::cout << "Method0 in sub class" << std::endl;
  }

  virtual void Method1 (int p0) override
  {
    std::cout << "Method1 in sub class, param0: " << p0 << std::endl;
  }

};

int main(int argc, char* argv[])
{
	using namespace BlendInt;

  TestClassBase obj1;
  TestClassDerived obj2;

	{
    Event<int> event;
    event.connect<TestClassBase, &TestClassBase::Method1>(&obj1);
    event.connect<TestClassDerived, &TestClassDerived::Method1>(&obj2);

    assert(event.count() == 2);
    event.fire(6);

    event.disconnect_all();
    assert(event.count() == 0);
	}

	{
    Event<int> event;
	  Connection<int> connection;
	  assert(connection.count() == 0);

	  connection.bind<TestClassBase, &TestClassBase::Method1>(event, &obj1);

	  event.fire(7);
	  assert(event.count() == 1);
	  assert(connection.count() == 1);
	}

	return 0;
}

