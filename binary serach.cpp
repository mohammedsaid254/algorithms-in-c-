
//Searching for the last True in TTTTTTTTTTTTTTFFFFFFFFFFFFF pattern 
int b_s(int s, int e){
      while (s < e){
            int mid = s + (e - s + 1) / 2;
            if (valid(mid))
                s = mid;
            else
                e = mid - 1;
      }
        return s;
} 


//Searching for the first True in FFFFFFFFTTTTTTTTT pattern 
int bs(int s, int e){
    while (s < e){
        int mid = (s + (e - s) / 2);
        if (valid(mid))
            e = mid;
        else  
            s = mid + 1;
    }
    
    return s;
}

