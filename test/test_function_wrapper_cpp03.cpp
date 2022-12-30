/******************************************************************************
The MIT License(MIT)

Embedded Template Library.
https://github.com/ETLCPP/etl
https://www.etlcpp.com

Copyright(c) 2022 John Wellbelove

Permission is hereby granted, free of charge, to any person obtaining a copy
of this software and associated documentation files(the "Software"), to deal
in the Software without restriction, including without limitation the rights
to use, copy, modify, merge, publish, distribute, sublicense, and / or sell
copies of the Software, and to permit persons to whom the Software is
furnished to do so, subject to the following conditions :

The above copyright notice and this permission notice shall be included in all
copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT.IN NO EVENT SHALL THE
AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
SOFTWARE.
******************************************************************************/

#include "unit_test_framework.h"

#define ETL_IN_FUNCTION_WRAPPER_CPP03_UNIT_TEST

#include "etl/function_wrapper.h"

#include <string>

using Data = std::string;

namespace
{
  //*****************************************************************************
  enum class FunctionCalled : int
  {
    Not_Called,
    Member_Return_Parameter_Called,
    Member_Return_Parameter_Alternate_Called,
    Member_Return_Parameter_Const_Called,
    Member_Parameter_Called,
    Member_Parameter_Alternate_Called,
    Member_Parameter_Const_Called,
    Member_Return_Called,
    Member_Return_Alternate_Called,
    Member_Return_Const_Called,
    Member_Called,
    Member_Alternate_Called,
    Member_Const_Called,
    Functor_Return_Parameter_Called,
    Functor_Return_Parameter_Alternate_Called,
    Functor_Return_Parameter_Const_Called,
    Functor_Return_Called,
    Functor_Return_Const_Called,
    Static_Return_Parameter_Called,
    Static_Return_Parameter_Alternate_Called,
    Static_Parameter_Called,
    Static_Parameter_Alternate_Called,
    Static_Return_Called,
    Static_Return_Alternate_Called,
    Static_Called,
    Static_Alternate_Called
  };

  FunctionCalled function_called;
  std::string    text_called;

  //***************************************************************************
  static std::string StaticReturnParameterFunction(const std::string& d_)
  {
    function_called = FunctionCalled::Static_Return_Parameter_Called;
    text_called     = d_;

    return text_called;
  }

  //***************************************************************************
  static Data StaticReturnParameterFunctionAlternate(const Data& d_)
  {
    function_called = FunctionCalled::Static_Return_Parameter_Alternate_Called;
    text_called     = d_;

    return d_;
  }

  //***************************************************************************
  static void StaticParameterFunction(const Data& d_)
  {
    function_called = FunctionCalled::Static_Parameter_Called;
    text_called     = d_; 
  }

  //***************************************************************************
  static void StaticParameterFunctionAlternate(const Data& d_)
  {
    function_called = FunctionCalled::Static_Parameter_Alternate_Called;
    text_called     = d_;
  }

  //***************************************************************************
  static Data StaticReturnFunction()
  {
    function_called = FunctionCalled::Static_Return_Called;
    text_called = "Static_Return_Called";

    return text_called;
  }

  //***************************************************************************
  static Data StaticReturnFunctionAlternate()
  {
    function_called = FunctionCalled::Static_Return_Alternate_Called;
    text_called     = "Static_Return_Alternate_Called";

    return text_called;
  }

  //***************************************************************************
  static void StaticFunction()
  {
    function_called = FunctionCalled::Static_Called;
    text_called     = "Static_Called";
  }

  //***************************************************************************
  static void StaticFunctionAlternate()
  {
    function_called = FunctionCalled::Static_Alternate_Called;
    text_called     = "Static_Alternate_Called";
  }

  //*****************************************************************************
  struct TestClass
  {
    //***********************************
    TestClass()
      : d("Not_Called")
    {
      function_called = FunctionCalled::Not_Called;
      text_called     = d;
    }

    //***********************************
    Data MemberReturnParameter(const Data& d_)
    {     
      d = d_;

      function_called = FunctionCalled::Member_Return_Parameter_Called;
      text_called     = d;

      return d_;
    }

    //***********************************
    Data MemberReturnParameterAlternate(const Data& d_)
    {
      d = d_;

      function_called = FunctionCalled::Member_Return_Parameter_Alternate_Called;
      text_called     = d;

      return d_;
    }

    //***********************************
    Data MemberReturnParameterConst(const Data& d_) const
    {
      d = d_;

      function_called = FunctionCalled::Member_Return_Parameter_Const_Called;
      text_called     = d;

      return d_;
    }

    //***********************************
    void MemberParameter(const Data& d_)
    {
      d = d_;

      function_called = FunctionCalled::Member_Parameter_Called;
      text_called     = d;
    }

    //***********************************
    void MemberParameterAlternate(const Data& d_)
    {
      d = d_;

      function_called = FunctionCalled::Member_Parameter_Alternate_Called;
      text_called     = d;
    }

    //***********************************
    void MemberParameterConst(const Data& d_) const
    {
      d = d_;

      function_called = FunctionCalled::Member_Parameter_Const_Called;
      text_called     = d;
    }

    //***********************************
    Data MemberReturn()
    {
      function_called = FunctionCalled::Member_Return_Called;
      text_called     = "Member_Return_Called";

      return text_called;
    }

    //***********************************
    Data MemberReturnAlternate()
    {
      function_called = FunctionCalled::Member_Return_Alternate_Called;
      text_called     = "Member_Return_Alternate_Called";

      return text_called;
    }

    //***********************************
    Data MemberReturnConst() const
    {
      function_called = FunctionCalled::Member_Return_Const_Called;
      text_called     = "Member_Return_Const_Called";

      return text_called;
    }

    //***********************************
    void Member()
    {
      function_called = FunctionCalled::Member_Called;
      text_called     = "Member_Called";
    }

    //***********************************
    void MemberAlternate()
    {
      function_called = FunctionCalled::Member_Alternate_Called;
      text_called     = "Member_Alternate_Called";
    }

    //***********************************
    void MemberConst() const
    {
      function_called = FunctionCalled::Member_Const_Called;
      text_called     = "Member_Const_Called";
    }

    mutable Data d;
  };

  //***************************************************************************
  struct Functor
  {
    //***********************************
    Functor()
      : d("Not_Called")
    {
    }

    //***********************************
    Functor(const Functor& other)
      : d(std::move(other.d))
    {
    }

    //***********************************
    Data operator()(const Data& d_)
    {
      function_called = FunctionCalled::Functor_Return_Parameter_Called;
      text_called     = "Functor_Return_Parameter_Called";

      return d_;
    }

    //***********************************
    Data operator()(const Data& d_) const
    {
      function_called = FunctionCalled::Functor_Return_Parameter_Const_Called;
      text_called     = "Functor_Return_Parameter_Const_Called";

      return d_;
    }

    //***********************************
    Data operator()()
    {
      function_called = FunctionCalled::Functor_Return_Called;
      text_called     = "Functor_Return_Called";

      return text_called;
    }

    //***********************************
    Data operator()() const
    {
      function_called = FunctionCalled::Functor_Return_Const_Called;
      text_called     = "Functor_Return_Const_Called";

      return text_called;
    }

    mutable Data d;
  };
  
  //***************************************************************************
  SUITE(test_member_function)
  {
    //*****************************************************************************
    // Initialises the test results.
    //*****************************************************************************
    struct SetupFixture
    {
      SetupFixture()
      {
        function_called = FunctionCalled::Not_Called;
        text_called     = "Not_Called";
      }
    };

    //*************************************************************************
    // Test Static Return Parameter Functions
    //*************************************************************************
    TEST_FIXTURE(SetupFixture, test_static_return_parameter_default_construction)
    {
      etl::function_wrapper<Data(const Data&)> func;
      CHECK_FALSE(func.is_valid());
      CHECK_FALSE(func);
      CHECK_THROW(Data result = func(Data("Static_Return_Parameter_Called")), etl::function_wrapper_uninitialised);
      CHECK_TRUE(function_called == FunctionCalled::Not_Called);
      CHECK_EQUAL("Not_Called", text_called);
    }

    //*************************************************************************
    TEST_FIXTURE(SetupFixture, test_static_return_parameter_default_construction_call_if)
    {
      etl::function_wrapper<Data(const Data&)> func;
      etl::optional<Data> result = func.call_if(Data("Static_Return_Parameter_Called"));
      CHECK_FALSE(result);
      CHECK_FALSE(func.is_valid());
      CHECK_FALSE(func);
      CHECK_TRUE(function_called == FunctionCalled::Not_Called);
      CHECK_EQUAL("Not_Called", text_called);
    }

    //*************************************************************************
    TEST_FIXTURE(SetupFixture, test_static_return_parameter_default_construction_call_or)
    {
      etl::function_wrapper<Data(const Data&)> func;
      etl::optional<Data> result = func.call_or(StaticReturnParameterFunctionAlternate, Data("Static_Return_Parameter_Alternate_Called"));
      CHECK_TRUE(result);
      CHECK_FALSE(func.is_valid());
      CHECK_FALSE(func);
      CHECK_TRUE(function_called == FunctionCalled::Static_Return_Parameter_Alternate_Called);
      CHECK_EQUAL("Static_Return_Parameter_Alternate_Called", text_called);
    }

    //*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_static_return_parameter)
    //{
    //  etl::function_wrapper<std::string(const std::string&)> func(StaticReturnParameterFunction);
    //  Data result = func(Data("Static_Return_Parameter_Called"));
    //  CHECK_TRUE(func.is_valid());
    //  CHECK_TRUE(func);
    //  CHECK_TRUE(function_called == FunctionCalled::Static_Return_Parameter_Called);
    //  CHECK_EQUAL("Static_Return_Parameter_Called", result);
    //  CHECK_EQUAL("Static_Return_Parameter_Called", text_called);
    //}

    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_static_return_parameter_call_if)
    //{
    //  etl::function_wrapper<Data(const Data&)> func(StaticReturnParameterFunction);
    //  etl::optional<Data> result = func.call_if(Data("Static_Return_Parameter_Called"));
    //  CHECK_TRUE(result);
    //  CHECK_TRUE(func.is_valid());
    //  CHECK_TRUE(func);
    //  CHECK_TRUE(function_called == FunctionCalled::Static_Return_Parameter_Called);
    //  CHECK_EQUAL("Static_Return_Parameter_Called", text_called);
    //  CHECK_EQUAL(result);
    //}

    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_static_return_parameter_call_or)
    //{
    //  etl::function_wrapper<Data(const Data&)> func(StaticReturnParameterFunction);
    //  etl::optional<Data> result = func.call_or(StaticReturnParameterFunctionAlternate, Data("Static_Return_Parameter_Called"));
    //  CHECK_TRUE(result);
    //  CHECK_TRUE(func.is_valid());
    //  CHECK_TRUE(func);
    //  CHECK_TRUE(function_called == FunctionCalled::Static_Return_Parameter_Called);
    //  CHECK_EQUAL("Static_Return_Parameter_Called", text_called);
    //  CHECK_EQUAL(result);
    //}

    ////*************************************************************************
    //// Test Static Parameter Functions
    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_static_parameter_default_construction)
    //{
    //  etl::function_wrapper<void(const Data&)> func;
    //  CHECK_FALSE(func.is_valid());
    //  CHECK_FALSE(func);
    //  CHECK_THROW(func(Data("Static_Parameter_Called")), etl::function_wrapper_uninitialised);
    //  CHECK_TRUE(function_called == FunctionCalled::Not_Called);
    //  CHECK_EQUAL("Not_Called", text_called);
    //}

    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_static_parameter_default_construction_call_if)
    //{
    //  etl::function_wrapper<void(const Data&)> func;
    //  func.call_if(Data("Static_Parameter_Called"));
    //  CHECK_FALSE(func.is_valid());
    //  CHECK_FALSE(func);
    //  CHECK_TRUE(function_called == FunctionCalled::Not_Called);
    //  CHECK_EQUAL("Not_Called", text_called);
    //}

    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_static_parameter_default_construction_call_or)
    //{
    //  etl::function_wrapper<void(const Data&)> func;
    //  func.call_or(StaticParameterFunctionAlternate, Data("Static_Parameter_Alternate_Called"));
    //  CHECK_FALSE(func.is_valid());
    //  CHECK_FALSE(func);
    //  CHECK_TRUE(function_called == FunctionCalled::Static_Parameter_Alternate_Called);
    //  CHECK_EQUAL("Static_Parameter_Alternate_Called", text_called);
    //}

    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_static_parameter)
    //{
    //  etl::function_wrapper<void(const Data&)> func(StaticParameterFunction);
    //  func(Data("Static_Parameter_Called"));
    //  CHECK_TRUE(func.is_valid());
    //  CHECK_TRUE(func);
    //  CHECK_TRUE(function_called == FunctionCalled::Static_Parameter_Called);
    //  CHECK_EQUAL("Static_Parameter_Called", text_called);
    //}

    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_static_parameter_call_if)
    //{
    //  etl::function_wrapper<void(const Data&)> func(StaticParameterFunction);
    //  func.call_if(Data("Static_Parameter_Called"));
    //  CHECK_TRUE(func.is_valid());
    //  CHECK_TRUE(func);
    //  CHECK_TRUE(function_called == FunctionCalled::Static_Parameter_Called);
    //  CHECK_EQUAL("Static_Parameter_Called", text_called);
    //}

    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_static_parameter_call_or)
    //{
    //  etl::function_wrapper<void(const Data&)> func(StaticParameterFunction);
    //  func.call_or(StaticParameterFunctionAlternate, Data("Static_Parameter_Called"));
    //  CHECK_TRUE(func.is_valid());
    //  CHECK_TRUE(func);
    //  CHECK_TRUE(function_called == FunctionCalled::Static_Parameter_Called);
    //  CHECK_EQUAL("Static_Parameter_Called", text_called);
    //}

    ////*************************************************************************
    //// Test Static Return Functions
    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_static_return_default_construction)
    //{
    //  etl::function_wrapper<Data()> func;
    //  CHECK_FALSE(func.is_valid());
    //  CHECK_FALSE(func);
    //  CHECK_THROW(Data result = func(), etl::function_wrapper_uninitialised);
    //}

    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_static_return_default_construction_call_if)
    //{
    //  etl::function_wrapper<Data()> func;
    //  etl::optional<Data> result = func.call_if();
    //  CHECK_FALSE(func.is_valid());
    //  CHECK_FALSE(func);
    //  CHECK_FALSE(result);
    //  CHECK_TRUE(function_called == FunctionCalled::Not_Called);
    //  CHECK_EQUAL("Not_Called", text_called);
    //}

    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_static_return_default_construction_call_or)
    //{
    //  etl::function_wrapper<Data()> func;
    //  etl::optional<Data> result = func.call_or(StaticReturnFunctionAlternate);
    //  CHECK_FALSE(func.is_valid());
    //  CHECK_FALSE(func);
    //  CHECK_TRUE(result);
    //  CHECK_TRUE(function_called == FunctionCalled::Static_Return_Alternate_Called);
    //  CHECK_EQUAL("Static_Return_Alternate_Called", text_called);
    //}

    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_static_return)
    //{
    //  etl::function_wrapper<Data()> func(StaticReturnFunction);
    //  Data result = func();
    //  CHECK_TRUE(func.is_valid());
    //  CHECK_TRUE(func);
    //  CHECK_EQUAL(result);
    //  CHECK_TRUE(function_called == FunctionCalled::Static_Return_Called);
    //  CHECK_EQUAL("Static_Return_Called", text_called);
    //}

    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_static_return_call_if)
    //{
    //  etl::function_wrapper<Data()> func(StaticReturnFunction);
    //  Data result = func.call_if();
    //  CHECK_TRUE(func.is_valid());
    //  CHECK_TRUE(func);
    //  CHECK_EQUAL(result);
    //  CHECK_TRUE(function_called == FunctionCalled::Static_Return_Called);
    //  CHECK_EQUAL("Static_Return_Called", text_called);
    //}

    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_static_return_call_or)
    //{
    //  etl::function_wrapper<Data()> func(StaticReturnFunction);
    //  Data result = func.call_or(StaticReturnFunctionAlternate);
    //  CHECK_TRUE(func.is_valid());
    //  CHECK_TRUE(func);
    //  CHECK_EQUAL(result);
    //  CHECK_TRUE(function_called == FunctionCalled::Static_Return_Called);
    //  CHECK_EQUAL("Static_Return_Called", text_called);
    //}

    ////*************************************************************************
    //// Test Static Functions
    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_static_default_construction)
    //{
    //  etl::function_wrapper<void()> func;
    //  CHECK_FALSE(func.is_valid());
    //  CHECK_FALSE(func);
    //  CHECK_THROW(func(), etl::function_wrapper_uninitialised);
    //  CHECK_TRUE(function_called == FunctionCalled::Not_Called);
    //  CHECK_EQUAL("Not_Called", text_called);
    //}

    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_static_default_construction_call_if)
    //{
    //  etl::function_wrapper<void()> func;
    //  func.call_if();
    //  CHECK_FALSE(func.is_valid());
    //  CHECK_FALSE(func);
    //  CHECK_TRUE(function_called == FunctionCalled::Not_Called);
    //  CHECK_EQUAL("Not_Called", text_called);
    //}

    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_static_default_construction_call_or)
    //{
    //  etl::function_wrapper<void()> func;
    //  func.call_or(StaticFunctionAlternate);
    //  CHECK_FALSE(func.is_valid());
    //  CHECK_FALSE(func);
    //  CHECK_TRUE(function_called == FunctionCalled::Static_Alternate_Called);
    //  CHECK_EQUAL("Static_Alternate_Called", text_called);
    //}

    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_static)
    //{
    //  etl::function_wrapper<void()> func(StaticFunction);
    //  func();
    //  CHECK_TRUE(func.is_valid());
    //  CHECK_TRUE(func);
    //  CHECK_TRUE(function_called == FunctionCalled::Static_Called);
    //  CHECK_EQUAL("Static_Called", text_called);
    //}

    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_static_call_if)
    //{
    //  etl::function_wrapper<void()> func(StaticFunction);
    //  func.call_if();
    //  CHECK_TRUE(func.is_valid());
    //  CHECK_TRUE(func);
    //  CHECK_TRUE(function_called == FunctionCalled::Static_Called);
    //  CHECK_EQUAL("Static_Called", text_called);
    //}

    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_static_call_or)
    //{
    //  etl::function_wrapper<void()> func(StaticFunction);
    //  func.call_or(StaticFunctionAlternate);
    //  CHECK_TRUE(func.is_valid());
    //  CHECK_TRUE(func);
    //  CHECK_TRUE(function_called == FunctionCalled::Static_Called);
    //  CHECK_EQUAL("Static_Called", text_called);
    //}

    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_static_return_parameter_assignment)
    //{
    //  etl::function_wrapper<Data(const Data&)> func1 = StaticReturnParameterFunction;
    //  etl::function_wrapper<Data(const Data&)> func2 = StaticReturnParameterFunctionAlternate;

    //  func2 = func1;

    //  Data result;

    //  result = func1(Data("Static_Return_Parameter_Called"));
    //  CHECK_TRUE(func1.is_valid());
    //  CHECK_TRUE(func1);
    //  CHECK_TRUE(function_called == FunctionCalled::Static_Return_Parameter_Called);
    //  CHECK_EQUAL("Static_Return_Parameter_Called", text_called);
    //  CHECK_EQUAL(result);

    //  result = func2(2, Data("Static_Return_Parameter_Called"));
    //  CHECK_TRUE(func2.is_valid());
    //  CHECK_TRUE(func2);
    //  CHECK_TRUE(function_called == FunctionCalled::Static_Return_Parameter_Called);
    //  CHECK_EQUAL("Static_Return_Parameter_Called", text_called);
    //  CHECK_EQUAL(2, result);
    //}

    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_static_return_parameter_equality)
    //{
    //  etl::function_wrapper<Data(const Data&)> func1;
    //  etl::function_wrapper<Data(const Data&)> func2;
    //  etl::function_wrapper<Data(const Data&)> func3(StaticReturnParameterFunction);
    //  etl::function_wrapper<Data(const Data&)> func4(StaticReturnParameterFunction);
    //  etl::function_wrapper<Data(const Data&)> func5(StaticReturnParameterFunctionAlternate);

    //  CHECK_TRUE(func1 == func2);
    //  CHECK_TRUE(func2 == func1);
    //  CHECK_TRUE(func3 == func4);
    //  CHECK_TRUE(func4 == func3);
    //  CHECK_TRUE(func1 != func3);
    //  CHECK_TRUE(func3 != func1);
    //  CHECK_TRUE(func1 != func4);
    //  CHECK_TRUE(func4 != func1);
    //  CHECK_TRUE(func4 != func5);
    //  CHECK_TRUE(func5 != func4);
    //}

    ////*************************************************************************
    //// Test Functor Functions
    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_functor_return_parameter)
    //{
    //  Functor functor;

    //  etl::function_wrapper<Data(const Data&)> func(functor);
    //  Data result = func(Data("Functor_Return_Parameter_Called"));
    //  CHECK_TRUE(func.is_valid());
    //  CHECK_TRUE(func);
    //  CHECK_TRUE(function_called == FunctionCalled::Functor_Return_Parameter_Called);
    //  CHECK_EQUAL("Functor_Return_Parameter_Called", text_called);
    //  CHECK_EQUAL(result);
    //}

    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_functor_return_parameter_const)
    //{
    //  const Functor functor;

    //  etl::function_wrapper<Data(const Data&)> func(functor);
    //  Data result = func(Data("Functor_Return_Parameter_Const_Called"));
    //  CHECK_TRUE(func.is_valid());
    //  CHECK_TRUE(func);
    //  CHECK_TRUE(function_called == FunctionCalled::Functor_Return_Parameter_Const_Called);
    //  CHECK_EQUAL("Functor_Return_Parameter_Const_Called", text_called);
    //  CHECK_EQUAL(result);
    //}

    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_functor_return)
    //{
    //  Functor functor;

    //  etl::function_wrapper<Data()> func(functor);
    //  Data result = func();
    //  CHECK_TRUE(func.is_valid());
    //  CHECK_TRUE(func);
    //  CHECK_TRUE(function_called == FunctionCalled::Functor_Return_Called);
    //  CHECK_EQUAL("Functor_Return_Called", text_called);
    //  CHECK_EQUAL(0, result);
    //}

    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_functor_return_const)
    //{
    //  const Functor functor;

    //  etl::function_wrapper<Data()> func(functor);
    //  Data result = func();
    //  CHECK_TRUE(func.is_valid());
    //  CHECK_TRUE(func);
    //  CHECK_TRUE(function_called == FunctionCalled::Functor_Return_Const_Called);
    //  CHECK_EQUAL("Functor_Return_Const_Called", text_called);
    //  CHECK_EQUAL(result);
    //}

    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_functor_return_parameter_assignment)
    //{
    //  Functor functor1;
    //  Functor functor2;

    //  etl::function_wrapper<Data(const Data&)> func1 = functor1;
    //  etl::function_wrapper<Data(const Data&)> func2 = functor2;

    //  func2 = func1;

    //  Data result;

    //  result = func1(Data("Functor_Return_Parameter_Called"));
    //  CHECK_TRUE(func1.is_valid());
    //  CHECK_TRUE(func1);
    //  CHECK_TRUE(function_called == FunctionCalled::Functor_Return_Parameter_Called);
    //  CHECK_EQUAL("Functor_Return_Parameter_Called", text_called);
    //  CHECK_EQUAL(result);

    //  result = func2(2, Data("Functor_Return_Parameter_Called"));
    //  CHECK_TRUE(func2.is_valid());
    //  CHECK_TRUE(func2);
    //  CHECK_TRUE(function_called == FunctionCalled::Functor_Return_Parameter_Called);
    //  CHECK_EQUAL("Functor_Return_Parameter_Called", text_called);
    //  CHECK_EQUAL(2, result);
    //}

    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_functor_return_parameter_equality)
    //{
    //  Functor functor1;
    //  Functor functor2;

    //  etl::function_wrapper<Data(const Data&)> func1;
    //  etl::function_wrapper<Data(const Data&)> func2;
    //  etl::function_wrapper<Data(const Data&)> func3(functor1);
    //  etl::function_wrapper<Data(const Data&)> func4(functor1);
    //  etl::function_wrapper<Data(const Data&)> func5(functor2);

    //  CHECK_TRUE(func1 == func2);
    //  CHECK_TRUE(func2 == func1);
    //  CHECK_TRUE(func3 == func4);
    //  CHECK_TRUE(func4 == func3);
    //  CHECK_TRUE(func1 != func3);
    //  CHECK_TRUE(func3 != func1);
    //  CHECK_TRUE(func1 != func4);
    //  CHECK_TRUE(func4 != func1);
    //  CHECK_TRUE(func4 != func5);
    //  CHECK_TRUE(func5 != func4);
    //}

    ////*************************************************************************
    //// Test Member Return Parameter Function
    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_member_return_parameter_default_construction)
    //{
    //  TestClass testClass;
    //  Data result;

    //  etl::function_wrapper<Data(TestClass&, int, const Data&)> func;
    //  CHECK_FALSE(func.is_valid());
    //  CHECK_FALSE(func);
    //  CHECK_THROW(result = func(testClass, Data("Not_Called")), etl::function_wrapper_uninitialised);
    //  CHECK_TRUE(function_called == FunctionCalled::Not_Called);
    //  CHECK_EQUAL("Not_Called", text_called);
    //}

    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_member_return_parameter_default_construction_call_if)
    //{
    //  TestClass testClass;

    //  etl::function_wrapper<Data(TestClass&, int, const Data&)> func;
    //  CHECK_FALSE(func.is_valid());
    //  CHECK_FALSE(func);
    //  etl::optional<Data> result = func.call_if(testClass, Data("Not_Called"));
    //  CHECK_FALSE(result.has_value());
    //  CHECK_TRUE(function_called == FunctionCalled::Not_Called);
    //  CHECK_EQUAL("Not_Called", text_called);
    //}

    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_member_return_parameter_default_construction_call_or)
    //{
    //  TestClass testClass;

    //  etl::function_wrapper<Data(TestClass&, int, const Data&)> func;
    //  CHECK_FALSE(func.is_valid());
    //  CHECK_FALSE(func);
    //  Data result = func.call_or(StaticReturnParameterFunction, testClass, Data("Static_Return_Parameter_Called"));
    //  CHECK_TRUE(function_called == FunctionCalled::Static_Return_Parameter_Called);
    //  CHECK_EQUAL("Static_Return_Parameter_Called", text_called);
    //}

    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_member_return_parameter)
    //{
    //  TestClass testClass;

    //  etl::function_wrapper<Data(TestClass&, int, const Data&)> func(&TestClass::MemberReturnParameter);
    //  Data result = func(testClass, Data("Member_Return_Parameter_Called"));
    //  CHECK_TRUE(func.is_valid());
    //  CHECK_TRUE(func);
    //  CHECK_TRUE(function_called == FunctionCalled::Member_Return_Parameter_Called);
    //  CHECK_EQUAL("Member_Return_Parameter_Called", text_called);
    //  CHECK_EQUAL(result);
    //}

    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_member_return_parameter_call_if)
    //{
    //  TestClass testClass;

    //  etl::function_wrapper<Data(TestClass&, int, const Data&)> func(&TestClass::MemberReturnParameter);
    //  etl::optional<Data> result = func.call_if(testClass, Data("Member_Return_Parameter_Called"));
    //  CHECK_TRUE(func.is_valid());
    //  CHECK_TRUE(func);
    //  CHECK_TRUE(function_called == FunctionCalled::Member_Return_Parameter_Called);
    //  CHECK_EQUAL("Member_Return_Parameter_Called", text_called);
    //  CHECK_TRUE(result.has_value());
    //  CHECK_EQUAL(result);
    //}

    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_member_return_parameter_call_or)
    //{
    //  TestClass testClass;

    //  etl::function_wrapper<Data(TestClass&, int, const Data&)> func(&TestClass::MemberReturnParameter);
    //  CHECK_TRUE(func.is_valid());
    //  CHECK_TRUE(func);
    //  Data result = func.call_or(StaticReturnParameterFunction, testClass, Data("Member_Return_Parameter_Called"));
    //  CHECK_TRUE(function_called == FunctionCalled::Member_Return_Parameter_Called);
    //  CHECK_EQUAL("Member_Return_Parameter_Called", text_called);
    //}

    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_member_return_parameter_const)
    //{
    //  TestClass testClass;

    //  etl::function_wrapper<Data(const TestClass&, int, const Data&)> func(&TestClass::MemberReturnParameterConst);
    //  Data result = func(testClass, Data("Member_Return_Parameter_Const_Called"));
    //  CHECK_TRUE(func.is_valid());
    //  CHECK_TRUE(func);
    //  CHECK_TRUE(function_called == FunctionCalled::Member_Return_Parameter_Const_Called);
    //  CHECK_EQUAL("Member_Return_Parameter_Const_Called", text_called);
    //  CHECK_EQUAL(result);
    //}

    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_member_return_parameter_const_assignment)
    //{
    //  TestClass testClass;

    //  etl::function_wrapper<Data(const TestClass&, int, const Data&)> func1(&TestClass::MemberReturnParameterConst);
    //  etl::function_wrapper<Data(const TestClass&, int, const Data&)> func2;

    //  func2 = func1;

    //  Data result;

    //  result = func1(testClass, Data("Member_Return_Parameter_Const_Called"));
    //  CHECK_TRUE(func1.is_valid());
    //  CHECK_TRUE(func1);
    //  CHECK_TRUE(function_called == FunctionCalled::Member_Return_Parameter_Const_Called);
    //  CHECK_EQUAL("Member_Return_Parameter_Const_Called", text_called);
    //  CHECK_EQUAL(result);

    //  result = func2(testClass, Data("Member_Return_Parameter_Const_Called"));
    //  CHECK_TRUE(func2.is_valid());
    //  CHECK_TRUE(func2);
    //  CHECK_TRUE(function_called == FunctionCalled::Member_Return_Parameter_Const_Called);
    //  CHECK_EQUAL("Member_Return_Parameter_Const_Called", text_called);
    //  CHECK_EQUAL(result);
    //}

    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_member_return_parameter_const_call_if)
    //{
    //  TestClass testClass;

    //  etl::function_wrapper<Data(const TestClass&, int, const Data&)> func(&TestClass::MemberReturnParameterConst);
    //  etl::optional<Data> result = func.call_if(testClass, Data("Member_Return_Parameter_Const_Called"));
    //  CHECK_TRUE(func.is_valid());
    //  CHECK_TRUE(func);
    //  CHECK_TRUE(function_called == FunctionCalled::Member_Return_Parameter_Const_Called);
    //  CHECK_EQUAL("Member_Return_Parameter_Const_Called", text_called);
    //  CHECK_TRUE(result.has_value());
    //  CHECK_EQUAL(result);
    //}

    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_member_return_parameter_const_call_or)
    //{
    //  TestClass testClass;

    //  etl::function_wrapper<Data(const TestClass&, int, const Data&)> func(&TestClass::MemberReturnParameterConst);
    //  CHECK_TRUE(func.is_valid());
    //  CHECK_TRUE(func);
    //  Data result = func.call_or(StaticReturnParameterFunction, testClass, Data("Member_Return_Parameter_Const_Called"));
    //  CHECK_TRUE(function_called == FunctionCalled::Member_Return_Parameter_Const_Called);
    //  CHECK_EQUAL("Member_Return_Parameter_Const_Called", text_called);
    //}

    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_member_return_parameter_default_construction_const_object)
    //{
    //  const TestClass testClass;
    //  Data result;

    //  etl::function_wrapper<Data(const TestClass&, int, const Data&)> func;
    //  CHECK_FALSE(func.is_valid());
    //  CHECK_FALSE(func);
    //  CHECK_THROW(result = func(testClass, Data("Not_Called")), etl::function_wrapper_uninitialised);
    //  CHECK_TRUE(function_called == FunctionCalled::Not_Called);
    //  CHECK_EQUAL("Not_Called", text_called);
    //}

    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_member_return_parameter_const_const_object)
    //{
    //  const TestClass testClass;

    //  etl::function_wrapper<Data(const TestClass&, int, const Data&)> func(&TestClass::MemberReturnParameterConst);
    //  Data result = func(testClass, Data("Member_Return_Parameter_Const_Called"));
    //  CHECK_TRUE(func.is_valid());
    //  CHECK_TRUE(func);
    //  CHECK_TRUE(function_called == FunctionCalled::Member_Return_Parameter_Const_Called);
    //  CHECK_EQUAL("Member_Return_Parameter_Const_Called", text_called);
    //  CHECK_EQUAL(result);
    //}

    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_member_return_parameter_assignment)
    //{
    //  TestClass testClass;

    //  etl::function_wrapper<Data(TestClass&, int, const Data&)> func1 = &TestClass::MemberReturnParameter;
    //  etl::function_wrapper<Data(TestClass&, int, const Data&)> func2 = &TestClass::MemberReturnParameterAlternate;

    //  func2 = func1;

    //  Data result;

    //  result = func1(testClass, Data("Member_Return_Parameter_Called"));
    //  CHECK_TRUE(func1.is_valid());
    //  CHECK_TRUE(func1);
    //  CHECK_TRUE(function_called == FunctionCalled::Member_Return_Parameter_Called);
    //  CHECK_EQUAL("Member_Return_Parameter_Called", text_called);
    //  CHECK_EQUAL(result);

    //  result = func2(testClass, 2, Data("Member_Return_Parameter_Called"));
    //  CHECK_TRUE(func2.is_valid());
    //  CHECK_TRUE(func2);
    //  CHECK_TRUE(function_called == FunctionCalled::Member_Return_Parameter_Called);
    //  CHECK_EQUAL("Member_Return_Parameter_Called", text_called);
    //  CHECK_EQUAL(2, result);
    //}

    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_member_return_parameter_equality)
    //{
    //  TestClass testClass;

    //  etl::function_wrapper<Data(TestClass&, int, const Data&)> func1;
    //  etl::function_wrapper<Data(TestClass&, int, const Data&)> func2;
    //  etl::function_wrapper<Data(TestClass&, int, const Data&)> func3(&TestClass::MemberReturnParameter);
    //  etl::function_wrapper<Data(TestClass&, int, const Data&)> func4(&TestClass::MemberReturnParameter);
    //  etl::function_wrapper<Data(TestClass&, int, const Data&)> func5(&TestClass::MemberReturnParameterAlternate);

    //  CHECK_TRUE(func1 == func2);
    //  CHECK_TRUE(func2 == func1);
    //  CHECK_TRUE(func3 == func4);
    //  CHECK_TRUE(func4 == func3);
    //  CHECK_TRUE(func1 != func3);
    //  CHECK_TRUE(func3 != func1);
    //  CHECK_TRUE(func1 != func4);
    //  CHECK_TRUE(func4 != func1);
    //  CHECK_TRUE(func4 != func5);
    //  CHECK_TRUE(func5 != func4);
    //}

    ////*************************************************************************
    //// Test Member Return Function
    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_member_return_default_construction)
    //{
    //  TestClass testClass;
    //  Data result;

    //  etl::function_wrapper<Data(TestClass&)> func;
    //  CHECK_FALSE(func.is_valid());
    //  CHECK_FALSE(func);
    //  CHECK_THROW(result = func(testClass), etl::function_wrapper_uninitialised);
    //  CHECK_TRUE(function_called == FunctionCalled::Not_Called);
    //  CHECK_EQUAL("Not_Called", text_called);
    //}

    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_member_return_default_construction_call_if)
    //{
    //  TestClass testClass;

    //  etl::function_wrapper<Data(TestClass&)> func;
    //  CHECK_FALSE(func.is_valid());
    //  CHECK_FALSE(func);
    //  etl::optional<Data> result = func.call_if(testClass);
    //  CHECK_FALSE(result.has_value());
    //  CHECK_TRUE(function_called == FunctionCalled::Not_Called);
    //  CHECK_EQUAL("Not_Called", text_called);
    //}

    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_member_return_default_construction_call_or)
    //{
    //  TestClass testClass;

    //  etl::function_wrapper<Data(TestClass&)> func;
    //  CHECK_FALSE(func.is_valid());
    //  CHECK_FALSE(func);
    //  Data result = func.call_or(StaticReturnFunction, testClass);
    //  CHECK_TRUE(function_called == FunctionCalled::Static_Return_Called);
    //  CHECK_EQUAL("Static_Return_Called", text_called);
    //}

    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_member_return)
    //{
    //  TestClass testClass;

    //  etl::function_wrapper<Data(TestClass&)> func(&TestClass::MemberReturn);
    //  Data result = func(testClass);
    //  CHECK_TRUE(func.is_valid());
    //  CHECK_TRUE(func);
    //  CHECK_TRUE(function_called == FunctionCalled::Member_Return_Called);
    //  CHECK_EQUAL("Member_Return_Called", text_called);
    //  CHECK_EQUAL(0, result);
    //}

    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_member_return_call_if)
    //{
    //  TestClass testClass;

    //  etl::function_wrapper<Data(TestClass&)> func(&TestClass::MemberReturn);
    //  etl::optional<Data> result = func.call_if(testClass);
    //  CHECK_TRUE(func.is_valid());
    //  CHECK_TRUE(func);
    //  CHECK_TRUE(function_called == FunctionCalled::Member_Return_Called);
    //  CHECK_EQUAL("Member_Return_Called", text_called);
    //  CHECK_TRUE(result.has_value());
    //  CHECK_EQUAL(0, result);
    //}

    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_member_return_call_or)
    //{
    //  TestClass testClass;

    //  etl::function_wrapper<Data(TestClass&)> func(&TestClass::MemberReturn);
    //  CHECK_TRUE(func.is_valid());
    //  CHECK_TRUE(func);
    //  Data result = func.call_or(StaticReturnFunction, testClass);
    //  CHECK_TRUE(function_called == FunctionCalled::Member_Return_Called);
    //  CHECK_EQUAL("Member_Return_Called", text_called);
    //}

    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_member_return_const)
    //{
    //  TestClass testClass;

    //  etl::function_wrapper<Data(const TestClass&)> func(&TestClass::MemberReturnConst);
    //  Data result = func(testClass);
    //  CHECK_TRUE(func.is_valid());
    //  CHECK_TRUE(func);
    //  CHECK_TRUE(function_called == FunctionCalled::Member_Return_Const_Called);
    //  CHECK_EQUAL("Member_Return_Const_Called", text_called);
    //  CHECK_EQUAL(result);
    //}

    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_member_return_const_call_if)
    //{
    //  TestClass testClass;

    //  etl::function_wrapper<Data(const TestClass&)> func(&TestClass::MemberReturnConst);
    //  etl::optional<Data> result = func.call_if(testClass);
    //  CHECK_TRUE(func.is_valid());
    //  CHECK_TRUE(func);
    //  CHECK_TRUE(function_called == FunctionCalled::Member_Return_Const_Called);
    //  CHECK_EQUAL("Member_Return_Const_Called", text_called);
    //  CHECK_TRUE(result.has_value());
    //  CHECK_EQUAL(result);
    //}

    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_member_return_const_call_or)
    //{
    //  TestClass testClass;

    //  etl::function_wrapper<Data(const TestClass&)> func(&TestClass::MemberReturnConst);
    //  CHECK_TRUE(func.is_valid());
    //  CHECK_TRUE(func);
    //  Data result = func.call_or(StaticReturnFunction, testClass);
    //  CHECK_TRUE(function_called == FunctionCalled::Member_Return_Const_Called);
    //  CHECK_EQUAL("Member_Return_Const_Called", text_called);
    //}

    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_member_return_default_construction_const_object)
    //{
    //  const TestClass testClass;

    //  etl::function_wrapper<Data(const TestClass&)> func;
    //  CHECK_THROW(Data result = func(testClass), etl::function_wrapper_uninitialised);
    //  CHECK_FALSE(func.is_valid());
    //  CHECK_FALSE(func);
    //}

    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_member_return_default_construction_const_object_call_if)
    //{
    //  const TestClass testClass;

    //  etl::function_wrapper<Data(const TestClass&)> func;
    //  CHECK_FALSE(func.is_valid());
    //  CHECK_FALSE(func);
    //  etl::optional<Data> result = func.call_if(testClass);
    //  CHECK_FALSE(result.has_value());
    //  CHECK_TRUE(function_called == FunctionCalled::Not_Called);
    //  CHECK_EQUAL("Not_Called", text_called);
    //}

    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_member_return_default_construction_const_object_call_or)
    //{
    //  const TestClass testClass;

    //  etl::function_wrapper<Data(const TestClass&)> func;
    //  CHECK_FALSE(func.is_valid());
    //  CHECK_FALSE(func);
    //  Data result = func.call_or(StaticReturnFunction, testClass);
    //  CHECK_TRUE(function_called == FunctionCalled::Static_Return_Called);
    //  CHECK_EQUAL("Static_Return_Called", text_called);
    //}

    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_member_return_const_const_object)
    //{
    //  const TestClass testClass;

    //  etl::function_wrapper<Data(const TestClass&)> func(&TestClass::MemberReturnConst);
    //  Data result = func(testClass);
    //  CHECK_TRUE(func.is_valid());
    //  CHECK_TRUE(func);
    //  CHECK_TRUE(function_called == FunctionCalled::Member_Return_Const_Called);
    //  CHECK_EQUAL("Member_Return_Const_Called", text_called);
    //  CHECK_EQUAL(result);
    //}

    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_member_return_const_const_object_call_if)
    //{
    //  const TestClass testClass;

    //  etl::function_wrapper<Data(const TestClass&)> func(&TestClass::MemberReturnConst);
    //  etl::optional<Data> result = func.call_if(testClass);
    //  CHECK_TRUE(func.is_valid());
    //  CHECK_TRUE(func);
    //  CHECK_TRUE(function_called == FunctionCalled::Member_Return_Const_Called);
    //  CHECK_EQUAL("Member_Return_Const_Called", text_called);
    //  CHECK_TRUE(result.has_value());
    //  CHECK_EQUAL(result);
    //}

    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_member_return_const_const_object_call_or)
    //{
    //  const TestClass testClass;

    //  etl::function_wrapper<Data(const TestClass&)> func(&TestClass::MemberReturnConst);
    //  CHECK_TRUE(func.is_valid());
    //  CHECK_TRUE(func);
    //  Data result = func.call_or(StaticReturnFunction, testClass);
    //  CHECK_TRUE(function_called == FunctionCalled::Member_Return_Const_Called);
    //  CHECK_EQUAL("Member_Return_Const_Called", text_called);
    //}

    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_member_return_assignment)
    //{
    //  TestClass testClass;

    //  etl::function_wrapper<Data(TestClass&)> func1 = &TestClass::MemberReturn;
    //  etl::function_wrapper<Data(TestClass&)> func2 = &TestClass::MemberReturnAlternate;

    //  func2 = func1;

    //  Data result;

    //  result = func1(testClass);
    //  CHECK_TRUE(func1.is_valid());
    //  CHECK_TRUE(func1);
    //  CHECK_TRUE(function_called == FunctionCalled::Member_Return_Called);
    //  CHECK_EQUAL("Member_Return_Called", text_called);
    //  CHECK_EQUAL(0, result);

    //  result = func2(testClass);
    //  CHECK_TRUE(func2.is_valid());
    //  CHECK_TRUE(func2);
    //  CHECK_TRUE(function_called == FunctionCalled::Member_Return_Called);
    //  CHECK_EQUAL("Member_Return_Called", text_called);
    //  CHECK_EQUAL(0, result);
    //}

    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_member_return_equality)
    //{
    //  TestClass testClass;

    //  etl::function_wrapper<Data(TestClass&)> func1;
    //  etl::function_wrapper<Data(TestClass&)> func2;
    //  etl::function_wrapper<Data(TestClass&)> func3(&TestClass::MemberReturn);
    //  etl::function_wrapper<Data(TestClass&)> func4(&TestClass::MemberReturn);
    //  etl::function_wrapper<Data(TestClass&)> func5(&TestClass::MemberReturnAlternate);

    //  CHECK_TRUE(func1 == func2);
    //  CHECK_TRUE(func2 == func1);
    //  CHECK_TRUE(func3 == func4);
    //  CHECK_TRUE(func4 == func3);
    //  CHECK_TRUE(func1 != func3);
    //  CHECK_TRUE(func3 != func1);
    //  CHECK_TRUE(func1 != func4);
    //  CHECK_TRUE(func4 != func1);
    //  CHECK_TRUE(func4 != func5);
    //  CHECK_TRUE(func5 != func4);
    //}

    ////*************************************************************************
    //// Test Member Parameter Function
    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_member_parameter_default_construction)
    //{
    //  TestClass testClass;

    //  etl::function_wrapper<void(TestClass&, int, const Data&)> func;
    //  CHECK_THROW(func(testClass, Data("Not_Called")), etl::function_wrapper_uninitialised);
    //  CHECK_FALSE(func.is_valid());
    //  CHECK_FALSE(func);
    //  CHECK_TRUE(function_called == FunctionCalled::Not_Called);
    //  CHECK_EQUAL("Not_Called", text_called);
    //}

    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_member_parameter_default_construction_call_if)
    //{
    //  TestClass testClass;

    //  etl::function_wrapper<void(TestClass&, int, const Data&)> func;
    //  CHECK_FALSE(func.is_valid());
    //  CHECK_FALSE(func);
    //  func.call_if(testClass, Data("Not_Called"));
    //  CHECK_TRUE(function_called == FunctionCalled::Not_Called);
    //  CHECK_EQUAL("Not_Called", text_called);
    //}

    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_member_parameter_default_construction_call_or)
    //{
    //  TestClass testClass;

    //  etl::function_wrapper<void(TestClass&, int, const Data&)> func;
    //  CHECK_FALSE(func.is_valid());
    //  CHECK_FALSE(func);
    //  func.call_or(StaticParameterFunction, testClass, Data("Static_Parameter_Function_Called"));
    //  CHECK_TRUE(function_called == FunctionCalled::Static_Parameter_Called);
    //  CHECK_EQUAL("Static_Parameter_Function_Called", text_called);
    //}

    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_member_parameter)
    //{
    //  TestClass testClass;

    //  etl::function_wrapper<void(TestClass&, int, const Data&)> func(&TestClass::MemberParameter);
    //  func(testClass, Data("Member_Parameter_Called"));
    //  CHECK_TRUE(func.is_valid());
    //  CHECK_TRUE(func);
    //  CHECK_TRUE(function_called == FunctionCalled::Member_Parameter_Called);
    //  CHECK_EQUAL("Member_Parameter_Called", text_called);
    //}

    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_member_parameter_call_if)
    //{
    //  TestClass testClass;

    //  etl::function_wrapper<void(TestClass&, int, const Data&)> func(&TestClass::MemberParameter);
    //  func.call_if(testClass, Data("Member_Parameter_Called"));
    //  CHECK_TRUE(func.is_valid());
    //  CHECK_TRUE(func);
    //  CHECK_TRUE(function_called == FunctionCalled::Member_Parameter_Called);
    //  CHECK_EQUAL("Member_Parameter_Called", text_called);
    //}

    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_member_parameter_call_or)
    //{
    //  TestClass testClass;

    //  etl::function_wrapper<void(TestClass&, int, const Data&)> func(&TestClass::MemberParameter);
    //  CHECK_TRUE(func.is_valid());
    //  CHECK_TRUE(func);
    //  func.call_or(StaticParameterFunction, testClass, Data("Member_Parameter_Called"));
    //  CHECK_TRUE(function_called == FunctionCalled::Member_Parameter_Called);
    //  CHECK_EQUAL("Member_Parameter_Called", text_called);
    //}

    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_member_parameter_const)
    //{
    //  TestClass testClass;

    //  etl::function_wrapper<void(const TestClass&, int, const Data&)> func(&TestClass::MemberParameterConst);
    //  func(testClass, Data("Member_Parameter_Const_Called"));
    //  CHECK_TRUE(func.is_valid());
    //  CHECK_TRUE(func);
    //  CHECK_TRUE(function_called == FunctionCalled::Member_Parameter_Const_Called);
    //  CHECK_EQUAL("Member_Parameter_Const_Called", text_called);
    //}

    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_member_parameter_default_construction_const_object)
    //{
    //  const TestClass testClass;

    //  etl::function_wrapper<void(const TestClass&, int, const Data&)> func;
    //  CHECK_THROW(func(testClass, Data("Not_Called")), etl::function_wrapper_uninitialised);
    //  CHECK_FALSE(func.is_valid());
    //  CHECK_FALSE(func);
    //}

    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_member_parameter_default_construction_const_object_call_if)
    //{
    //  const TestClass testClass;

    //  etl::function_wrapper<Data(const TestClass&, int, const Data&)> func;
    //  CHECK_FALSE(func.is_valid());
    //  CHECK_FALSE(func);
    //  etl::optional<Data> result = func.call_if(testClass, Data("Not_Called"));
    //  CHECK_FALSE(result.has_value());
    //  CHECK_TRUE(function_called == FunctionCalled::Not_Called);
    //  CHECK_EQUAL("Not_Called", text_called);
    //}

    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_member_parameter_default_construction_const_object_call_or)
    //{
    //  const TestClass testClass;

    //  etl::function_wrapper<Data(const TestClass&, int, const Data&)> func;
    //  CHECK_FALSE(func.is_valid());
    //  CHECK_FALSE(func);
    //  Data result = func.call_or(StaticReturnParameterFunction, testClass, Data("Static_Return_Parameter_Called"));
    //  CHECK_TRUE(function_called == FunctionCalled::Static_Return_Parameter_Called);
    //  CHECK_EQUAL("Static_Return_Parameter_Called", text_called);
    //}

    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_member_parameter_const_const_object)
    //{
    //  const TestClass testClass;

    //  etl::function_wrapper<void(const TestClass&, int, const Data&)> func(&TestClass::MemberParameterConst);
    //  func(testClass, Data("Member_Parameter_Const_Called"));
    //  CHECK_TRUE(func.is_valid());
    //  CHECK_TRUE(func);
    //  CHECK_TRUE(function_called == FunctionCalled::Member_Parameter_Const_Called);
    //  CHECK_EQUAL("Member_Parameter_Const_Called", text_called);
    //}

    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_member_parameter_const_const_object_call_if)
    //{
    //  const TestClass testClass;

    //  etl::function_wrapper<void(const TestClass&, int, const Data&)> func(&TestClass::MemberParameterConst);
    //  func.call_if(testClass, Data("Member_Parameter_Const_Called"));
    //  CHECK_TRUE(func.is_valid());
    //  CHECK_TRUE(func);
    //  CHECK_TRUE(function_called == FunctionCalled::Member_Parameter_Const_Called);
    //  CHECK_EQUAL("Member_Parameter_Const_Called", text_called);
    //}

    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_member_parameter_const_const_object_call_or)
    //{
    //  const TestClass testClass;

    //  etl::function_wrapper<void(const TestClass&, int, const Data&)> func(&TestClass::MemberParameterConst);
    //  CHECK_TRUE(func.is_valid());
    //  CHECK_TRUE(func);
    //  func.call_or(StaticParameterFunction, testClass, Data("Member_Parameter_Const_Called"));
    //  CHECK_TRUE(function_called == FunctionCalled::Member_Parameter_Const_Called);
    //  CHECK_EQUAL("Member_Parameter_Const_Called", text_called);
    //}

    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_member_parameter_return_assignment)
    //{
    //  TestClass testClass;

    //  etl::function_wrapper<void(TestClass&, int, const Data&)> func1 = &TestClass::MemberParameter;
    //  etl::function_wrapper<void(TestClass&, int, const Data&)> func2 = &TestClass::MemberParameterAlternate;

    //  func2 = func1;

    //  func1(testClass, Data("Member_Parameter_Return_Called"));
    //  CHECK_TRUE(func1.is_valid());
    //  CHECK_TRUE(func1);
    //  CHECK_TRUE(function_called == FunctionCalled::Member_Parameter_Called);
    //  CHECK_EQUAL("Member_Parameter_Return_Called", text_called);

    //  func2(testClass, 2, Data("Member_Parameter_Return_Called"));
    //  CHECK_TRUE(func2.is_valid());
    //  CHECK_TRUE(func2);
    //  CHECK_TRUE(function_called == FunctionCalled::Member_Parameter_Called);
    //  CHECK_EQUAL("Member_Parameter_Return_Called", text_called);
    //}

    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_member_parameter_equality)
    //{
    //  TestClass testClass;

    //  etl::function_wrapper<void(TestClass&, int, const Data&)> func1;
    //  etl::function_wrapper<void(TestClass&, int, const Data&)> func2;
    //  etl::function_wrapper<void(TestClass&, int, const Data&)> func3(&TestClass::MemberParameter);
    //  etl::function_wrapper<void(TestClass&, int, const Data&)> func4(&TestClass::MemberParameter);
    //  etl::function_wrapper<void(TestClass&, int, const Data&)> func5(&TestClass::MemberParameterAlternate);

    //  CHECK_TRUE(func1 == func2);
    //  CHECK_TRUE(func2 == func1);
    //  CHECK_TRUE(func3 == func4);
    //  CHECK_TRUE(func4 == func3);
    //  CHECK_TRUE(func1 != func3);
    //  CHECK_TRUE(func3 != func1);
    //  CHECK_TRUE(func1 != func4);
    //  CHECK_TRUE(func4 != func1);
    //  CHECK_TRUE(func4 != func5);
    //  CHECK_TRUE(func5 != func4);
    //}

    ////*************************************************************************
    //// Test Member Function
    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_member_default_construction)
    //{
    //  TestClass testClass;

    //  etl::function_wrapper<void(TestClass&)> func;
    //  CHECK_THROW(func(testClass), etl::function_wrapper_uninitialised);
    //  CHECK_FALSE(func.is_valid());
    //  CHECK_FALSE(func);
    //  CHECK_TRUE(function_called == FunctionCalled::Not_Called);
    //  CHECK_EQUAL("Not_Called", text_called);
    //}

    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_member_default_construction_call_if)
    //{
    //  TestClass testClass;

    //  etl::function_wrapper<void(TestClass&)> func;
    //  CHECK_FALSE(func.is_valid());
    //  CHECK_FALSE(func);
    //  func.call_if(testClass);
    //  CHECK_TRUE(function_called == FunctionCalled::Not_Called);
    //  CHECK_EQUAL("Not_Called", text_called);
    //}

    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_member_default_construction_call_or)
    //{
    //  TestClass testClass;

    //  etl::function_wrapper<void(TestClass&)> func;
    //  CHECK_FALSE(func.is_valid());
    //  CHECK_FALSE(func);
    //  func.call_or(StaticFunction, testClass);
    //  CHECK_TRUE(function_called == FunctionCalled::Static_Called);
    //  CHECK_EQUAL("Static_Called", text_called);
    //}

    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_member)
    //{
    //  TestClass testClass;

    //  etl::function_wrapper<void(TestClass&)> func(&TestClass::Member);
    //  func(testClass);
    //  CHECK_TRUE(func.is_valid());
    //  CHECK_TRUE(func);
    //  CHECK_TRUE(function_called == FunctionCalled::Member_Called);
    //  CHECK_EQUAL("Member_Called", text_called);
    //}

    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_member_call_if)
    //{
    //  TestClass testClass;

    //  etl::function_wrapper<void(TestClass&)> func(&TestClass::Member);
    //  CHECK_TRUE(func.is_valid());
    //  CHECK_TRUE(func);
    //  func.call_if(testClass);
    //  CHECK_TRUE(function_called == FunctionCalled::Member_Called);
    //  CHECK_EQUAL("Member_Called", text_called);
    //}

    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_member_call_or)
    //{
    //  TestClass testClass;

    //  etl::function_wrapper<void(TestClass&)> func(&TestClass::Member);
    //  CHECK_TRUE(func.is_valid());
    //  CHECK_TRUE(func);
    //  func.call_or(StaticFunction, testClass);
    //  CHECK_TRUE(function_called == FunctionCalled::Member_Called);
    //  CHECK_EQUAL("Member_Called", text_called);
    //}

    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_member_call_or_constexpr)
    //{
    //  TestClassConstexpr testClass;

    //  etl::function_wrapper<void(const TestClassConstexpr&)> func(&TestClassConstexpr::MemberConst);
    //  CHECK_TRUE(func.is_valid());
    //  CHECK_TRUE(func);
    //  func.call_or(StaticFunctionConstexpr, testClass);
    //}

    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_member_const)
    //{
    //  TestClass testClass;

    //  etl::function_wrapper<void(const TestClass&)> func(&TestClass::MemberConst);
    //  func(testClass);
    //  CHECK_TRUE(func.is_valid());
    //  CHECK_TRUE(func);
    //  CHECK_TRUE(function_called == FunctionCalled::Member_Const_Called);
    //  CHECK_EQUAL("Member_Const_Called", text_called);
    //}

    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_member_const_call_if)
    //{
    //  TestClass testClass;

    //  etl::function_wrapper<void(const TestClass&)> func(&TestClass::MemberConst);
    //  CHECK_TRUE(func.is_valid());
    //  CHECK_TRUE(func);
    //  func.call_if(testClass);
    //  CHECK_TRUE(function_called == FunctionCalled::Member_Const_Called);
    //  CHECK_EQUAL("Member_Const_Called", text_called);
    //}

    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_member_const_call_or)
    //{
    //  TestClass testClass;

    //  etl::function_wrapper<void(const TestClass&)> func(&TestClass::MemberConst);
    //  CHECK_TRUE(func.is_valid());
    //  CHECK_TRUE(func);
    //  func.call_or(StaticFunction, testClass);
    //  CHECK_TRUE(function_called == FunctionCalled::Member_Const_Called);
    //  CHECK_EQUAL("Member_Const_Called", text_called);
    //}

    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_member_default_construction_const_object)
    //{
    //  const TestClass testClass;

    //  etl::function_wrapper<void(const TestClass&)> func;
    //  CHECK_THROW(func(testClass), etl::function_wrapper_uninitialised);
    //  CHECK_FALSE(func.is_valid());
    //  CHECK_FALSE(func);
    //  CHECK_TRUE(function_called == FunctionCalled::Not_Called);
    //  CHECK_EQUAL("Not_Called", text_called);
    //}

    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_member_default_construction_const_object_call_if)
    //{
    //  const TestClass testClass;

    //  etl::function_wrapper<void(const TestClass&)> func;
    //  CHECK_FALSE(func.is_valid());
    //  CHECK_FALSE(func);
    //  func.call_if(testClass);
    //  CHECK_TRUE(function_called == FunctionCalled::Not_Called);
    //  CHECK_EQUAL("Not_Called", text_called);
    //}

    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_member_default_construction_const_object_call_or)
    //{
    //  const TestClass testClass;

    //  etl::function_wrapper<void(const TestClass&)> func;
    //  CHECK_FALSE(func.is_valid());
    //  CHECK_FALSE(func);
    //  func.call_or(StaticFunction, testClass);
    //  CHECK_TRUE(function_called == FunctionCalled::Static_Called);
    //  CHECK_EQUAL("Static_Called", text_called);
    //}

    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_member_const_const_object)
    //{
    //  const TestClass testClass;

    //  etl::function_wrapper<void(const TestClass&)> func(&TestClass::MemberConst);
    //  func(testClass);
    //  CHECK_TRUE(func.is_valid());
    //  CHECK_TRUE(func);
    //  CHECK_TRUE(function_called == FunctionCalled::Member_Const_Called);
    //  CHECK_EQUAL("Member_Const_Called", text_called);
    //}

    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_member_const_const_object_call_if)
    //{
    //  const TestClass testClass;

    //  etl::function_wrapper<void(const TestClass&)> func(&TestClass::MemberConst);
    //  CHECK_TRUE(func.is_valid());
    //  CHECK_TRUE(func);
    //  func.call_if(testClass);
    //  CHECK_TRUE(function_called == FunctionCalled::Member_Const_Called);
    //  CHECK_EQUAL("Member_Const_Called", text_called);
    //}

    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_member_const_const_object_call_or)
    //{
    //  const TestClass testClass;

    //  etl::function_wrapper<void(const TestClass&)> func(&TestClass::MemberConst);
    //  CHECK_TRUE(func.is_valid());
    //  CHECK_TRUE(func);
    //  func.call_or(StaticFunction, testClass);
    //  CHECK_TRUE(function_called == FunctionCalled::Member_Const_Called);
    //  CHECK_EQUAL("Member_Const_Called", text_called);
    //}

    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_member_assignment)
    //{
    //  TestClass testClass;

    //  etl::function_wrapper<void(TestClass&)> func1 = &TestClass::Member;
    //  etl::function_wrapper<void(TestClass&)> func2 = &TestClass::MemberAlternate;

    //  func2 = func1;

    //  func1(testClass);
    //  CHECK_TRUE(func1.is_valid());
    //  CHECK_TRUE(func1);
    //  CHECK_TRUE(function_called == FunctionCalled::Member_Called);
    //  CHECK_EQUAL(text_called, "Member_Called");

    //  func2(testClass);
    //  CHECK_TRUE(func2.is_valid());
    //  CHECK_TRUE(func2);
    //  CHECK_TRUE(function_called == FunctionCalled::Member_Called);
    //  CHECK_EQUAL("Member_Called", text_called);
    //}

    ////*************************************************************************
    //TEST_FIXTURE(SetupFixture, test_member_equality)
    //{
    //  TestClass testClass;

    //  etl::function_wrapper<void(TestClass&)> func1;
    //  etl::function_wrapper<void(TestClass&)> func2;
    //  etl::function_wrapper<void(TestClass&)> func3(&TestClass::Member);
    //  etl::function_wrapper<void(TestClass&)> func4(&TestClass::Member);
    //  etl::function_wrapper<void(TestClass&)> func5(&TestClass::MemberAlternate);

    //  CHECK_TRUE(func1 == func2);
    //  CHECK_TRUE(func2 == func1);
    //  CHECK_TRUE(func3 == func4);
    //  CHECK_TRUE(func4 == func3);
    //  CHECK_TRUE(func1 != func3);
    //  CHECK_TRUE(func3 != func1);
    //  CHECK_TRUE(func1 != func4);
    //  CHECK_TRUE(func4 != func1);
    //  CHECK_TRUE(func4 != func5);
    //  CHECK_TRUE(func5 != func4);
    //}
  };
}
