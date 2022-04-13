namespace Bandersnatch
{
    public class SetWeapon
    {
        /*protected string name;
        protected double failure;
        protected int usage;
        protected double damage;
        string name, double failure, int usage, double damage)*/
        public void SetValue(Weapon selected)
        {
            switch (selected.type)
            {
                case 0: //bow_and_arrow
                {
                    selected.failure = 0.5;
                    selected.damage = 27.5;
                    selected.usage = 4;
                    break;
                }
                case 1: //sword
                {
                    break;

                }
                case 2: //crossbow
                {
                    break;

                }
                case 3: //axe
                {
                    break;

                }
                case 4: //dagger
                {
                    break;
                }
                case 5: //magic_staff
                {
                    break;
                }
                case 6: //fire_ball
                {
                    break;
                }
                case 7: //fist
                {
                    break;
                }
                case 8: //healing_potion
                {
                    break;
                }
            }
        }
    }
}