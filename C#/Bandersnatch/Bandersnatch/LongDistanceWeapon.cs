namespace Bandersnatch
{
    public class BowAndArrow : Weapon
    {
        public BowAndArrow(int type, string name, double failure, int usage, double damage) : base(type, name, failure,
            usage, damage)
        {
        } 
        
        void ReduceLife(Player aPlayer) 
        { 
            aPlayer.life = -Damage; 
        }
    }

    public class Crossbow : Weapon
    {
        public Crossbow(int type, string name, double failure, int usage, double damage) : base(type, name, failure,
            usage, damage)
        {
        } 
        
        void ReduceLife(Player aPlayer) 
        { 
            aPlayer.life = -Damage; 
        }
    }

    public class MagicStaff : Weapon
    {
        public MagicStaff(int type, string name, double failure, int usage, double damage) : base(type, name, failure,
            usage, damage)
        {
        } 
        
        void ReduceLife(Player aPlayer) 
        { 
            aPlayer.life = -Damage; 
        }
    }

    public class FireBall : Weapon
    {
        public FireBall(int type, string name, double failure, int usage, double damage) : base(type, name, failure,
            usage, damage)
        {
        } 
        
        void ReduceLife(Player aPlayer) 
        { 
            aPlayer.life = -Damage; 
        }
    }
}

