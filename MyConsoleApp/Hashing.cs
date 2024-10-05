

using System.Text;

public class Hashing
{
  public static void SayHello() => Console.WriteLine("Hashing says Majani Life!");
  
  #region LongestConseqSequence
  public static void LongestConseqSequence(){
    var arr = new List<int> { 2, 6, 1, 9, 4, 5, 3 };
    Console.WriteLine(findSequence(arr));
  }

    private static int findSequence(List<int> arr)
    {
    int n = arr.Count;
    int max = 0;
    var nums = new HashSet<int>();
    arr.ForEach(x =>
    {
      nums.Add(x);
      max = Math.Max(x, max);
    });
    int len = 0;
    int maxlen = 1;
    for(int i = 0; i <= max; i++){
      if(nums.Contains(i)){
        len++;
        maxlen = Math.Max(len, maxlen);
      }
      else{
        len = 0;
      }
    }
    return maxlen;
    }
    #endregion
  #region All Fibbonaccis
  public static void FindFibos(){
    var arr = new List<int> { 0, 2, 8, 5, 2, 1, 4, 13, 23 };
    var ans = AllFibbos(arr);
    Console.Write("[ ");
    ans.ForEach(x => Console.Write(x + " "));
    Console.Write("]\n");
  }

    private static List<int> AllFibbos(List<int> arr)
    {
    var res = new List<int>();
    var fibbo = new HashSet<int>();
    int max = arr.Max();
    int fib1 = 0;
    int fib2 = 1;
    fibbo.Add(fib1);
    fibbo.Add(fib2);
    while(fib2 <= max){
      int fib = fib1 + fib2;
      fibbo.Add(fib);
      fib1 = fib2;
      fib2 = fib;
    }
    arr.ForEach(x =>
    {
      if (fibbo.Contains(x))
      {
        res.Add(x);
      }
    });
    return res;
    }
    #endregion
  #region MinLenWithAllChars
  public static void MinLenWithAllChars(){
    string str = "AABBCBBDCBA";
    Console.WriteLine(findMinLenSubString(str));
  }

    private static int findMinLenSubString(string str)
    {
    var uqchars = new HashSet<int>();
    foreach(var s in str){
      uqchars.Add(s);
    }
    int minlen = str.Length;
    int head = 0, tail = head;
    var charfreq = new Dictionary<char, int>();
    while(tail < str.Length){
      charfreq.AddFreq(str[tail]);
      while(charfreq.Count == uqchars.Count && head <= tail){
        minlen = Math.Min(tail - head + 1, minlen);
        charfreq[str[head]]--;
        if(charfreq[str[head]] == 0){
          charfreq.Remove(str[head]);
        }
        head++;
      }
      tail++;
    }
    return minlen;
    }

    #endregion

}
