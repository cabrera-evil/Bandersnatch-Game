using System;

namespace Bandersnatch
{
    public class shop
    {
        public void ShopMenu()
        {
            Console.WriteLine("Menu de compra de armas.\n"+
                              "1. Espada\n"+
                              "2. Arco y flecha\n"+
                              "3. Ballesta\n"+
                              "4. Hacha\n"+
                              "5. Daga\n" +
                              "6. Baston Magico\n"+
                              "7. Bola de fuego\n" +
                              "8. Posion curativa\n"+
                              "Escriba su selecion:");
            int option = Convert.ToInt16(Console.ReadLine());
            switch(option)
            {
                case 1:
                {
                    break;
                }
                case 2:
                {
                    Weapon Arco = new Weapon(0, "Arco y flecha", 0, 0, 0);
                    SetWeapon update = new SetWeapon();
                    update.SetValue(Arco);
                    Console.WriteLine("Arco y flecha comprado exitosamente");
                    break;
                }
            }
        }
    }
}