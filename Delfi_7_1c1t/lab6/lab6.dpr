program lab6;

{$APPTYPE CONSOLE}

uses
  SysUtils;

Type
  node=^_node;
  _node=record
    x:string;
    r:node;
    rev:string
  end;
  Hash=object
    mass:array of node;
    constructor HashNew;
    procedure add(x:string);
    function find(x:string):node;
  end;

  constructor Hash.HashNew;
  var
    i:integer;
  begin
    setlength(mass,29);
    for i:=0 to length(mass)-1 do
    begin
      mass[i]:=new(node);
      mass[i]:=nil;
    end;
  end;

  function h(x:string):integer;
  var
    temp:int64;
    p,i,sum:integer;
  begin
    p:=1;
    temp:=0;
    sum:=0;
    for i:=1 to length(x) do
    begin
      temp:=temp+Integer(x[i])*p;
      p:=p*31;
      sum:=sum+integer(x[i]);
    end;
    temp:=temp * sum;
    temp:=temp mod 29;
    h:=temp;
  end;

  procedure Hash.add(x:string);
  var
    temp:node;
    num:integer;
  begin
    num:=h(x);
    if mass[num]=nil then
    begin
      mass[num]:=new(node);
      mass[num]^.x:=x;
      mass[num]^.r:=nil;
    end else
    begin
      temp:=new(node);
      temp:=mass[num];
      while temp^.r<>nil do
        temp:=temp^.r;
      temp^.r:=new(node);
      temp^.r^.x:=x;
      temp^.r^.r:=nil;
    end;
  end;
function Hash.find(x:string):node;
var
  num:integer;
  temp:node;
begin
  temp:=mass[h(x)];
  while (temp<>nil) and (temp^.x<>x) do
  begin
    temp:=temp^.r;
  end;
  if temp<> nil then find:=temp else find:=nil;

end;

var
  obj:Hash;
  temp:string;
  ch:char;
  tmp:int64;
  i:integer;
  mass:array of integer;
begin
  obj.HashNew;
  for i:=0 to 1000 do
  begin
    write(h(intToStr(i)), ' ');
    obj.add(intToStr(i));
  end;
  obj.add('3450');
  writeln;
  writeln(obj.find('3450')<>nil);



  Readln;
  { TODO -oUser -cConsole Main : Insert code here }
end.
