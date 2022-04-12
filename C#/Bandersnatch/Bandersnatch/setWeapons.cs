namespace Bandersnatch
{
    public class setWeapons
    {
        /*protected string name;
        protected double failure;
        protected int usage;
        protected double damage;
        string name, double failure, int usage, double damage)*/
        
        public void setValue(weapon selected){
            switch(selected.id)
            {
                case 0://bow_and_arrow
                {
                    selected.name = "Arco con flechas";
                    selected.failure = 0.5;
                    selected.damage = 27.5;
                 }
                case 1://sword
                {
                    
                }
                case 2://crossbow
                {
                
                }
                case 3://axe
                {
                
                }
                case 4://dagger
                {
                
                }
                case 5://magic_staff
                {
                
                }
                case 6://fire_ball
                {
                
                }
                case 7://fist
                {
                    
                }
                case 8://healing_potion
                {
                
                }
            }
        }
    }
}