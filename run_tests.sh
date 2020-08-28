EXEC=$1
TMP_OUT=$2

for i in {1..8..1}; do
  testname=$(printf "%02d" $i)
  $EXEC input/$testname.in > $TMP_OUT
  if ! diff -qwB test/$testname.out $TMP_OUT &>/dev/null; then
    echo "Test $testname failed"
  else
    echo "Test $testname passed"
  fi
done
rm $TMP_OUT