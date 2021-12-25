//program.cs
using System;
using System.Runtime.InteropServices;
using SR2ATLAutoSvrLib;

namespace SR2DotNetClient
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("SR2 Kotsuba D 00321");

            ISR2MyMath math = new SR2MyMath();
            Console.WriteLine($"fun141: (151 + 149)/2 = {math.fun141(151, 149)}");

            Console.WriteLine($"fun142: 8 * 3 * 5 = {math.fun142(81, 74, 18)}");

            Console.WriteLine($"fun143: 11 to pound 2 = {math.fun143(11)}");

            Marshal.ReleaseComObject(math);

            Console.ReadKey();


        }
    }
}
