
public class LineSweep
{
  public static void SayHello() => Console.WriteLine("LineSweep says Namaste!");
  
  public static void MaxIntersections(){
    // Input
    var lines = new List<List<int>>
    {
      new() {1, 3}, 
      new() {2, 3}, 
      new() {1, 2}, 
      new() {4, 4}
    };
    // Output
    Console.WriteLine(MaxIntersectionPoint(lines));
  }

    private static int MaxIntersectionPoint(List<List<int>> lines)
    {
      var sortedPts = new SortedDictionary<int, int>();
      lines.ForEach(x =>
      {
        int start = x[0];
        int end = x[1] + 1;
        if(sortedPts.ContainsKey(start)){
          sortedPts[start]++;
        }
        else{
          sortedPts[start] = 1;
        }
        if(sortedPts.ContainsKey(end)){
          sortedPts[end]--;
        }
        else{
          sortedPts[end] = -1;
        }
      });
      int i = 0;
      int maxi = 0;
      foreach (var point in sortedPts)
      {
        i += point.Value;
        maxi = Math.Max(i, maxi);
      }
      return maxi;
    }

    public static void MaxGuests(){
      int guests = 5;
      int[] Entry = {1, 2,10, 5, 5};
      int[] Exit = {4, 5, 12, 9, 12};
    MaxIntervalsOverlap(guests, Entry, Exit).ForEach(x => Console.Write(x + " "));
    //Console.WriteLine(MaxIntervalsOverlap(guests, Entry, Exit));
    }

    private static List<int> MaxIntervalsOverlap(int guests, int[] entry, int[] exit)
    {
    Array.Sort(entry);
    Array.Sort(exit);
    int g = 1;
    int maxg = g;
    int mint = entry[0];
    int n = 1, x = 0;
    while(n < guests && x < guests){
      if(entry[n] <= exit[x]){
        g++;
        if(maxg < g){
          maxg = g;
          mint = entry[n];
        }
        n++;
      }
      else{
        g--;
        x++;
      }
    }
    return new List<int> { maxg, mint };
    }

}
