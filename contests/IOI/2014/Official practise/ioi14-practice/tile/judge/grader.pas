program grader;

uses tile;

function max(a, b, c: longint): longint;
begin
	if b > a then a := b;
	if c > a then a := c;
	max := a;
end;

function min(a, b, c: longint): longint;
begin
	if b < a then a := b;
	if c < a then a := c;
	min := a;
end;

procedure bye;
begin
	writeln('incorrect.');
	halt;
end;

var
	n, x, y: longint;
	t: tileType;
	s, m: longint;
	f: array[0..255, 0..255] of boolean;
	i: longint;

procedure checkxy(x, y: longint);
begin
	if (x < 0) or (x >= s) or (y < 0) or (y >= s) then bye;
	if f[x, y] then bye;
	f[x, y] := true;
end;

procedure check(x1, y1, x2, y2, x3, y3: longint);
begin
	checkxy(x1, y1);
	checkxy(x2, y2);
	checkxy(x3, y3);
	if max(x1, x2, x3) <> min(x1, x2, x3) + 1 then bye;
	if max(y1, y2, y3) <> min(y1, y2, y3) + 1 then bye;
	if (x1 = x2) and (y1 = y2) then bye;
	if (x1 = x3) and (y1 = y3) then bye;
	if (x2 = x3) and (y2 = y3) then bye;
end;

begin
	read(n, x, y);
	s := 1 shl n;
	placeTile(n, x, y, t);
	m := s * s div 3;
	for i := 0 to m - 1 do
		check(t[i, 0], t[i, 1], t[i, 2], t[i, 3], t[i, 4], t[i, 5]);
	writeln(y, '~', n, '~', x, '~', n * x * y);

end.
