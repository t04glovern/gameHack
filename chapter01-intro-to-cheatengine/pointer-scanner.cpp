/* pointerScan()

The pointerScan() function is the entry point to the scan. It takes the param-
eters target (the dynamic memory address to find), maxAdd (the maximum
value of any offset), and maxDepth (the maximum length of the pointer path).
It then loops through every 4-byte aligned address in the game, calling
rScan() with the parameters address (the address in the current iteration),
target, maxAdd, maxDepth, and curDepth (the depth of the path, which is always 1
in this case).
*/
list<int> pointerScan(target, maxAdd, maxDepth) {
	for(address = BASE, 0x7FFFFFF, 4) {
		ret = rScan(address, target, maxAdd, maxDepth, 1);
		if (ret.len > 0) {
			ret.pushFront(address);
			return ret;
		}
	}
	return {};
}

/* rScan()

The rScan() function reads memory from every 4-byte aligned offset between
0 and maxAdd, and returns if a result is equal to  target. If rScan() doesn’t
return in the first loop and the recursion is not too deep, it increments
curDepth and again loops over each offset, calling itself for each iteration.

If a self call returns a partial pointer path, rScan() will prepend the
current offset to the path and return up the recursion chain until it
reaches pointerScan(). When a call to rScan() from pointerScan() returns a
pointer path, pointerScan() pushes the current address to the front of the
path and returns it as a complete chain.
*/
list<int> rScan(address target, maxAdd, maxDepth, curDepth) {
	for(offset = 0, maxAdd, 4) {
		value = read(address + offset);
		if(value == target) {
			return list<int>(offset);
		}
	}
	return {};
}