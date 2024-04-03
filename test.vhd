-- AND gate VHDL implementation

-- Entity declaration
entity AND_gate is
    Port ( input_1 : in  std_logic;
           input_2 : in  std_logic;
           output : out  std_logic);
end AND_gate;

-- Architecture
architecture Behavioral of AND_gate is
begin
    -- AND operation
    output <= input_1 and input_2;
end Behavioral;
