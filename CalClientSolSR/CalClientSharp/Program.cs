//Program.cs
using System;
using MSACAL;

namespace CalClientSharp
{
    class Program
    {
        static void Main(string[] args)
        {
            Console.WriteLine("SR3 00321 kotsubad");
            var obj = new Calendar();

            Console.WriteLine("Текущий год " + obj.Year);
            Console.WriteLine("Текущий месяц " + obj.Month);
            

            obj.Month = 6;
            obj.Year = 1997;

            Console.WriteLine("Обновленный год " + obj.Year);
            Console.WriteLine("Обновленный месяц " + obj.Month);

            Console.ReadKey();
        }
    }
}
