<?php

function maching($str,$substr,$pos = 1)
{
    if($pos <= 0){
        exit("pos 的位置必须大于等于1");
    }
    $res = initial($str,$substr);

    $strArray = $res[0];
    $substrArray = $res[1];

    $i = $pos;
    $j = 1;
    while ($i <= $strArray[0] && $j <= $substrArray[0]){
        //下面这条语句的意思是当从子串的第一个字符开始匹配时，如果此时父串
        //匹配位置以后的长度小于子串的长度那么就没有必要再循环下去了，因为
        //根本匹配不到，这条语句会增加匹配不到情况下的效率，如果能匹配到那么
        //对效率没有影响
        if($j == 1 && ($strArray[0] - $i + 1 <$substrArray[0])) break;
        if($strArray[$i] == $substrArray[$j]){
            $i++;
            $j++;
        }
        else{
            $i = $i - $j + 2;
            $j = 1;
        }
    }

    if($j > $substrArray[0]) return $i-$j+1;
    else return 0;
}

function initial($str,$substr)
{
   $first[0] = strlen($str);
   $second[0] = strlen($substr);

   for($i = 0; $i < $first[0]; $i++){
       $first[] = $str[$i];
   }

   for($i = 0; $i < $second[0]; $i++){
       $second[] = $substr[$i];
   }

   return [$first,$second];
}

$str1 = 'goodgooglgoogle';
$str2 = 'google';
var_dump(maching($str1,$str2));