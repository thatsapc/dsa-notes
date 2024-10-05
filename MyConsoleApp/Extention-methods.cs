public static class Extensions{
   
    public static void AddFreq<TKey>(this Dictionary<TKey, int> dict, TKey key)
    where TKey : notnull
    {
      if(dict.ContainsKey(key)){
      dict[key]++;
      }
      else{
      dict[key] = 1;
      }
    }
}