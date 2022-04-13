using System;

namespace Bandersnatch
{
    public class Weapon: damage, heal
    {
        private int Id;
        private int Type;
        private string Name;
        private double Failure;
        private int Usage;
        protected double Damage;
        
        public int id
        {
            get => Id;
            set => Id = value;
        }

        public string name
        {
            get => Name;
            set => Name = value;
        }

        public double failure
        {
            get => Failure;
            set => Failure = value;
        }

        public int usage
        {
            get => Usage;
            set => Usage = value;
        }

        public double damage
        {
            get => Damage;
            set => Damage = value;
        }
        public int type
        {
            get => Type;
            set => Type = value;
        }

        private Random identify = new Random();
        public Weapon(int type, string name, double failure, int usage, double damage)
        {
          
            this.Id = identify.Next(0, 1000);
            this.Type = type;
            this.Name = name;
            this.Failure = failure;
            this.Usage = usage;
            this.Damage = damage;
        }
        public override string ToString()
        {
            return "ID: "+Id+"\nName: "+Name+"\nFailure probability: "+Failure+"\nUsage: "+ Usage+"\nDamage: "+Damage+"\n";
        }

        public virtual void ReduceLife()
        {
            Console.WriteLine("¡Reduciendo vida del jugador!");
        }

        public virtual void AddLife()
        {
            Console.WriteLine("¡Añadiendo vida al jugador!");
        }

    }
    
}