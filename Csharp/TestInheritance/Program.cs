using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace TestInheritance
{
    class BaseClass
    {
        // Unrestricted access
        public int myPublic;
        
        // Defining assembly or derived class
        protected internal int myProtInt;
        
        // Defining assembly
        internal int myInternal;

        // Defining or derived class
        protected int myProtected;
        
        // Defining class only
        private int myPrivate;

        public void SimpleFunc()
        {
            Console.WriteLine("In Base::SimpleFunc");
        }
        public virtual void FuncToOverride()
        {
            Console.WriteLine("In Base::FuncToOverride");
        }
        public void FuncToHide()
        {
            Console.WriteLine("In Base::FuncToHide");
        }
    }

    class DerivedClass : BaseClass 
    {
        public override void FuncToOverride()
        {
            Console.WriteLine("In Derived::FuncToOverride");
            // base.FuncToOverride();
        }
        public new void FuncToHide()
        {
            Console.WriteLine("In Derived::FuncToHide");
        }

        void Test()
        {
            myPublic = 0; // allowed
            myProtInt = 0; // allowed
            myInternal = 0; // allowed
            myProtected = 0; // allowed
            // myPrivate = 0; // inaccessible
        }
    }

    // Defining assembly
    class AnyClass
    {
        void Test(BaseClass m)
        {
            m.myPublic = 0; // allowed
            m.myProtInt = 0; // allowed
            m.myInternal = 0; // allowed
            // m.myProtected = 0; // inaccessible
            // m.myPrivate = 0; // inaccessible
        }
    }

    // idemo dodati Extension method u izvedenu klasu
    static class ExtMethods
    {
        public static void ProsirenaMetoda(this DerivedClass d)
        {
            Console.WriteLine("Prosirena metoda!!!");
        }
    }

    class Program
    {
        static void Main(string[] args)
        {
            BaseClass a = new BaseClass();
            DerivedClass b = new DerivedClass();
            BaseClass c = new DerivedClass();

            a.SimpleFunc();
            a.FuncToOverride();
            a.FuncToHide();

            b.SimpleFunc();
            b.FuncToOverride();
            b.FuncToHide();

            c.SimpleFunc();
            c.FuncToOverride();
            c.FuncToHide();

            // extension method
            b.ProsirenaMetoda();
        }
    }
}
