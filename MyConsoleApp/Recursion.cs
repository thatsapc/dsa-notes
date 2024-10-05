
public class Recursion{
  public static void SayHello() => Console.WriteLine("Recursion says Wannakam!");

  #region Lucky Numenrs
  public static void LuckyNumber(){
    int N = 5;
    int remove = 2;
    var lucky = isLucky(N, remove) ? "lucky" : "unlucky";
    Console.WriteLine(N + " is " + lucky);
  }

    private static bool isLucky(int n, int remove)
    {
      // base case
      if(n < remove){
      return true;
      }
      if (n % remove == 0) return false;
      else{
        int next = n - (n / remove);
        return isLucky(next, ++remove);
      }
    }
    #endregion
}