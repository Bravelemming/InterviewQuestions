class UsingForEach {
  public static void main(String[] args) 
  {
    String[] arrData = {"Alpha", "Beta", "Gamma", "Delta", "Sigma"};
    //The conventional approach of using the for loop
    System.out.println("Using conventional For Loop:");
      for(int i=0; i< arrData.length; i++)
      {
        System.out.println(arrData[i]);
      }
    
    System.out.println("\nUsing Foreach loop:");
    //The optimized method of using the for loop - also called the foreach loop
    for (String strTemp : arrData)
    {
      System.out.println(strTemp);
    }

    
  }//end main
}//end class