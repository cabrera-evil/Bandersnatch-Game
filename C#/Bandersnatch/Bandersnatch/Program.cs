using System;
using System.Collections.Generic;

namespace Bandersnatch
{
    public class Program
    {
        public static void Main(string[] args)
        {
            int option = -1;
            while (option != 2)
            {
                Console.Write("Menu inicial.\n" +
                              "1. Comprar armas\n" +
                              "2. Salir\n" +
                              "Selecione su opcion: ");
                option = Convert.ToInt16(Console.ReadLine());
                switch (option)
                {
                    case 1:
                    {
                        shop shop = new shop();
                        shop.ShopMenu();
                        break;
                    }
                    case 2:
                    {
                        break;
                    }
                }
            }
        }
    }
} 