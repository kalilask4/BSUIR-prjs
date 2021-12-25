using System;
using System.Runtime.InteropServices;
using Interop.Server;

namespace DotNetClient
{
    class Program
    {
        static void Main(string[] args)
        {
            var obj = new COMDemo();
            IWelcome welcome = obj;
            Console.WriteLine("C# client. 00321. Labs 3-4");
            Console.WriteLine(welcome.Greeting("Diana"));
            IMath math;
            math = (IMath)welcome;
            Console.Write("4 + 23 = ");
            Console.WriteLine(math.Add(4, 23));
            Console.Write("4 - 23 = ");
            Console.WriteLine(math.Sub(4, 23));
            Console.Write("4 * 941 = ");
            Console.WriteLine(math.Mul(4, 941));
            Console.Write("78 / 23 = ");
            Console.WriteLine(math.Div(78, 23));
            Console.Write("78 / 0 = ");
            try
            {
                Console.WriteLine(math.Div(78, 0)); //try to handle null div exception
            }
                       
            catch (COMException e)
            {
                Console.WriteLine("Exception caught: {0}", e.Message);
                if (e.ErrorCode == -2147417851)
                {
                    Console.WriteLine($"Zero dividion exception. {e.StackTrace}");
                }

                //Console.WriteLine("Exception caught: {0}", e.InnerException);
                //Console.WriteLine("Eerrorcode: {0}", e.ErrorCode);
                //Console.WriteLine("HResult: {0}", e.HResult);
                //Console.WriteLine("Data: {0}", e.Data);
                //Console.WriteLine("trace: {0}", e.StackTrace);
            }

            //Console.WriteLine("C# client.00321. SR v14");

            Console.ReadKey();
            
            //принудительно уменьшим количество ссылок
            Marshal.ReleaseComObject(math);

        }
    }
}
