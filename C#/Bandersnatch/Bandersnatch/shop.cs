using System;

namespace Bandersnatch
{
    public class shop
    {
        public void ShopMenu()
        {
            Console.Write("Buy your weapons.\n"+
                              "1. Sword\n"+
                              "2. Bow and Arrow\n"+
                              "3. Crossbow\n"+
                              "4. Axe\n"+
                              "5. Dagger\n" +
                              "6. Magic Staff\n"+
                              "7. Fire Ball\n" +
                              "8. Healing potion\n"+
                              "Your selection: ");
            int option = Convert.ToInt16(Console.ReadLine());
            switch(option)
            {
                case 1:
                {
                    break;
                }
                case 2:
                {
                    Console.Write("\nWeapon Stats:\n"+
                                      "-Name: Bow and Arrow\n"+
                                      "-Failure probability: 50%\n"+
                                      "-Usage: 4\n" +
                                      "-Damage: 27.5\n"+
                                      "Buy this weapon?(1-Yes o 2-No): ");
                    option = Convert.ToInt16(Console.ReadLine());
                    if (option == 1)
                    {
                        Weapon Arco = new Weapon(0, "Bow and Arrow", 0, 0, 0);
                        SetWeapon update = new SetWeapon();
                        update.SetValue(Arco);
                        Console.Write("Bow and Arrow Purchased Successfully");
                        break;
                    }
                    else
                    {
                        ShopMenu();
                    }
                    break;
                }
            }
        }
    }
}