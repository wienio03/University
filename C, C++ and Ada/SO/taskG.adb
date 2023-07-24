with Ada.Text_IO; use Ada.Text_IO;
package body Rozwiazanie is
   task body Synchronizator is
      type TaskArray is array(1..5) of Integer;
      Tasks : TaskArray;
      Turns : Integer := 0;
      Threads : Integer := 5;
      DONE : Boolean := False;
      counter : Integer := 1;
      isAllowed : Boolean;
      procedure sortThreads(Arr : in out TaskArray) is
      tmp : Integer;
      begin
         for I in 1..5 loop
            for J in I..5 loop
               if Arr(I) < Arr(J) then
                  tmp := Arr(I);
                  Arr(I) := Arr(J);
                  Arr(J) := tmp;
               end if;
            end loop;
         end loop;      
      end sortThreads;
   begin
      --logowanie watkow
      for I in 1..5 loop
         accept logowanie(id : Integer) do 
            Tasks(I) := id;
         end logowanie;
      end loop;
      
      while DONE = False loop
         while counter <= Threads loop
            sortThreads(Tasks);
            accept chcePracowac(id : Integer; zgoda : out Boolean) do
               if Tasks(counter) = id then
                  counter := counter + 1;
                  zgoda := True;
                  isAllowed := zgoda;
               else 
                  zgoda := False;
               end if;
            end chcePracowac;
            if isAllowed then
               select
                  accept ponownie do
                     null;
                  end ponownie;
                 
               or
                  accept koniec do
                     counter := counter - 1;
                     Threads := Threads - 1;
                     Tasks(counter) := -1000;
                     sortThreads(Tasks);
                  end koniec;
               end select;
            end if;
            
         end loop;
         counter := 1;
         --inkrementacja tur
         Turns := Turns + 1;
         --sprawdzenie czy juz koniec
         if Turns = 3  or Threads = 0 then
            Done := True;
         end if;
         
      end loop;
      
      
      
   end Synchronizator;

end Rozwiazanie;
