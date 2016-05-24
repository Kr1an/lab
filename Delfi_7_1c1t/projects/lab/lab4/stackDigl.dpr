program stackDigl;

{$APPTYPE CONSOLE}

uses
  SysUtils;

type
  node=^_node;
  _node=record
    x:integer;
    r:node;
    l:node;
  end;
  stack=object
    top:node;
    bottom:node;
    constructor stackNew;
    procedure push(_x:integer);
    procedure pop;
    function peek:integer;
    procedure VerCommFuncFStack;
    procedure show;
  end;
constructor stack.stackNew;
begin
  new(top);
  top^.l:=nil;
  top^.r:=nil;
  top^.x:=0;
  bottom:=top;
end;
procedure stack.push(_x:integer);
var
  temp:node;
begin
  top^.x:=_x;
  new(temp);
  temp^.l:=top;
  temp^.r:=nil;
  temp^.x:=0;
  top^.r:=temp;
  top:=temp;
end;
procedure stack.pop;
begin
  if (top^.l<>nil) or (top^.r<>nil) then
  begin
    top:=top^.l;
    top^.r:=nil;
    top^.x:=0;
  end;
end;
function stack.peek:integer;
begin
  if top^.l<>nil then
    peek:=top^.l^.x
  else exit;
end;
procedure stack.VerCommFuncFStack;
var
  temp:node;
  tmp:integer;
begin
    temp:=bottom;

    while temp^.r<>nil do
    begin
      tmp:=temp^.r^.x;
      if(temp^.x<0) and (temp^.r^.r<>nil) then
      begin
        temp^.r:=temp^.r^.r;
        temp^.r^.l:=temp;
        if(tmp>=0)then
      begin

        temp:=temp^.r;
      end;
      end else
      begin
        temp:=temp^.r;
      end;
    end;
end;
  procedure stack.show;
  var
    temp:node;
  begin
    temp:=bottom;
    while(temp<>top) do
    begin
      write(temp^.x, ' ');
      temp:=temp^.r;
    end;
    writeln;
  end;
var
  obj:stack;
  i:integer;
begin
  obj.stackNew;
  obj.push(1);
  obj.push(-2);
  obj.push(-3);
  obj.push(6);
  obj.push(5);
  obj.push(-5);
  obj.push(-2);
  obj.push(-1);
  obj.push(7);
  obj.push(8);
  obj.show;
  obj.VerCommFuncFStack;
  obj.show;
  readln;
  { TODO -oUser -cConsole Main : Insert code here }
end.
