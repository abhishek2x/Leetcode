
int fountainActivation() {
    int dp[N];
     
      for(int i=0;i<N;i++){
          dp[i]=-1;
    }
     int idxLeft;
 
    int idxRight;
 
    for (int i = 0; i < N; i++) {
        idxLeft = max(i - a[i], 0);
        idxRight = min(i + (a[i] + 1), N);
        dp[idxLeft] = max(dp[idxLeft],
                          idxRight);
    }
 
    int cntfount = 1;
    idxRight = dp[0];
    int idxNext=-1;
 
    for (int i = 0; i < N; i++)
    {
        idxNext = max(idxNext, dp[i]);
                      
        if (i == idxRight)
        {
            cntfount++;
            idxRight = idxNext;
        }
    }
 
    return cntfount;
}