make clean
make

echo "test1 diff..."
./disklab < traces/test1.trace > t1_a.txt
./disklab-ref < traces/test1.trace > t1_b.txt
diff t1_a.txt t1_b.txt

echo "test2 diff..."
./disklab < traces/test2.trace > t2_a.txt
./disklab-ref < traces/test2.trace > t2_b.txt
diff t2_a.txt t2_b.txt

echo "test3 diff..."
./disklab < traces/test3.trace > t3_a.txt
./disklab-ref < traces/test3.trace > t3_b.txt
diff t3_a.txt t3_b.txt

echo "test4 diff..."
./disklab < traces/test4.trace > t4_a.txt
./disklab-ref < traces/test4.trace > t4_b.txt
diff t4_a.txt t4_b.txt

