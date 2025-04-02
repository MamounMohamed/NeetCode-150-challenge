class Solution {

    /**
     * @param Integer[] $nums
     * @return Integer
     */
    function firstMissingPositive($nums) {
        $containsOne = 0 ;
        $n = count($nums);

        if($n == 1 ){
            if($nums[0] == 1)
                return 2;
            else 
                return 1;
        }
        for ($i = 0 ; $i < $n ; $i++){
            if($nums[$i] ==1)
                $containsOne = 1 ;
            
            if($nums[$i] <= 0 || $nums[$i] > $n )
                $nums[$i] = 1 ;

        }
        if(!$containsOne){
            return 1 ;
        }

        for($i = 0 ; $i <$n ;$i++)
        {
            $num = abs($nums[$i]);
            if($num == $n)
                $nums[0] = -abs($nums[0]);
            else 
                $nums[$num] = -abs($nums[$num]);            
        }
        
        for($i = 1 ; $i<$n ; $i++){
            if($nums[$i] > 0 )
            {
                return $i  ;
            }
        }

        if($nums[0] < 0)
            return $n+1;
        else 
            return $n;
    }
}