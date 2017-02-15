using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TestDelegatesEvents
{
    delegate void MyDelegate();

    delegate int LambdaDel(int x);

    class A
    {
        public delegate void MemberFuncDelegate(int b);

        private int _a;

        public A(int inA)
        {
            _a = inA;
        }
        public void TestFunc1()
        {
            Console.WriteLine("TestFunc1, a = {0}", _a);
        }
        public void TestFunc2(int b)
        {
            Console.WriteLine("TestFunc2, a = {0}, b = {1}", _a, b);
        }
    }

    public delegate void EventDelegate(object o, System.EventArgs arg);

    class Publisher
    {
        public event EventDelegate Added;

        public void OnOperationThatWillNotify(System.EventArgs e)
        {
            if( Added != null )
                Added(this, e);
        }

        public void Operation()
        {
            // nešto radimo
            // i onda treba dignuti event
            OnOperationThatWillNotify(System.EventArgs.Empty);
        }
    }

    class Subscriber
    {
        public void OperationEventHandler(object sender, System.EventArgs e)
        {
            Console.WriteLine("Event raised");
        }
    }
    class Program
    {
        static void Main(string[] args)
        {
            A newObjA = new A(10);

            MyDelegate ptrFunc = newObjA.TestFunc1;
            ptrFunc();

            A.MemberFuncDelegate ptr2 = newObjA.TestFunc2;
            ptr2(20);

            // Lambda expression
            LambdaDel b = (int x) => x * x ;

            Publisher p = new Publisher();
            Subscriber s = new Subscriber();

            p.Added += s.OperationEventHandler;

            p.Operation();
        }
    }
}
