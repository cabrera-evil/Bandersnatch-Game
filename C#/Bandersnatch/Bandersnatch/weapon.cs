namespace Bandersnatch
{
    public abstract class weapon
    {
        protected int id;
        protected string name;
        protected double failure;
        protected int usage;
        protected double damage;

        protected weapon(int id, string name, double failure, int usage, double damage)
        {
            this.id = id;
            this.name = name;
            this.failure = failure;
            this.usage = usage;
            this.damage = damage;
        }
    }
    public class Sword : weapon
    {
        public Sword(int id, string name, double failure, int usage, double damage) : base(id, name, failure, usage, damage)
        {
            this.id = id;
            this.name = name;
            this.failure = failure;
            this.usage = usage;
            this.damage = damage;
        }
    }

    public class BowAndArrow : weapon
    {
        public BowAndArrow(int id, string name, double failure, int usage, double damage) : base(id, name, failure, usage, damage)
        {
            this.id = id;
            this.name = name;
            this.failure = failure;
            this.usage = usage;
            this.damage = damage;
        }
    }
    public class MagicStaff : weapon
    {
        public MagicStaff(int id, string name, double failure, int usage, double damage) : base(id, name, failure, usage, damage)
        {
            this.id = id;
            this.name = name;
            this.failure = failure;
            this.usage = usage;
            this.damage = damage;
        }
    }
    public class FireBall : weapon
    {
        public FireBall(int id, string name, double failure, int usage, double damage) : base(id, name, failure, usage, damage)
        {
            this.id = id;
            this.name = name;
            this.failure = failure;
            this.usage = usage;
            this.damage = damage;
        }
    }
    public class Crossbow : weapon
    {
        public Crossbow(int id, string name, double failure, int usage, double damage) : base(id, name, failure, usage, damage)
        {
            this.id = id;
            this.name = name;
            this.failure = failure;
            this.usage = usage;
            this.damage = damage;
        }
    }
    public class Axe : weapon
    {
        public Axe(int id, string name, double failure, int usage, double damage) : base(id, name, failure, usage, damage)
        {
            this.id = id;
            this.name = name;
            this.failure = failure;
            this.usage = usage;
            this.damage = damage;
        }
    }
}