#!/usr/bin/perl

$output = "student.out";
$probs = "student.probs";
$correct = "correct.out";

#get rid of old outputs
system "rm -f $output";
system "rm -f $probs";

#run your arrayList program
system "arrayList > $output";

#compare to the correct one
system "diff $output $correct > $probs";
$probFileSize = -s $probs;
$outputFileSize = -s $output;

if ($outputFileSize == 0)
{
   print "Failed.\n";
   print "Your program produced no output.\n";
}
elsif ($probFileSize > 0) 
{
   print "Failed.\n";
   print "See differences in file $probs.\n";
   print "Your output lines begin with a '<' in that file.\n";
   print "The correct output lines begin with a '>'.\n";
} else
{
   system "rm -f $probs";
   print "Passed.\n";
   print "Your output in $output matches the correct output.\n";
}   
