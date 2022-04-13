using System;
using System.Collections.Generic;

namespace Bandersnatch
{
    public class Program
    {
        public static void Main(string[] args)
        {
            Console.WriteLine("Menu inicial.\n"+
                              "1. Comprar armas\n"+
                              "Selecione su opcion:");
            int option = Convert.ToInt16(Console.ReadLine());
            switch (option)
            {
                case 1:
                {
                    shop shop = new shop();
                    shop.ShopMenu();
                    break;
                }
            }
        }
    }
} 