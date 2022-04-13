using System;
using System.Collections.Generic;

namespace Bandersnatch
{
    public class Program
    {
        public static void Main(string[] args)
        {
            int option = 0;
            bool exit = false;
            do
            {
                Console.Write("\n----------------------------------\n" +
                              "MAIN MENU\n" +
                              "1. Buy Weapons\n" +
                              "2. Exit\n" +
                              "----------------------------------\n"+
                              "Your selection: ");
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
                        exit = true;
                        break;
                    }
                }
            } while(!exit);
        }
    }
} 