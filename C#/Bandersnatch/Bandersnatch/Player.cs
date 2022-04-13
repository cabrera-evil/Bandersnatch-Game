namespace Bandersnatch
{
    public class Player
    {
        private string name;
        private double _life;

        public double life
        {
            get { return _life; }
            set { _life = value; }
        }

        public Player(string name, double life)
        {
            this.name = name;
            this._life = life; 
        }
    }
}