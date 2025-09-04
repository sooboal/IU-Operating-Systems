#!/bash/bin

# -i -> case insenstitve, -c count the number of occurenceses, -n -> show line numbers
# If your termianl doesn't have these highlight thingies on, use --color=auto
grep -i -n "expecto" Harry.txt
# grep -i -c "expecto" Harry.txt
# grep -i --color=auto "expecto" Harry.txt

