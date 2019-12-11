program grader;

uses station;

var
	n, k: longint;
	m: LodgeType;
	i: longint;

begin
	read(n, k);
	for i := 0 to n - 1 do read(m[i]);
	writeln(findMinDays(n, k, m));

end.
