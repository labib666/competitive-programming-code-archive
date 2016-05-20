program grader;

uses square;

var
	n: longint;
	m: materialType;
	i, j: longint;

begin
	read(n);
	for i := 0 to n - 1 do for j := 0 to n - 1 do read(m[i, j]);
	writeln(findMaxSquare(m, n));

end.
