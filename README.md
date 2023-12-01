# season-2-SE-my_mouse
<div class="card-block">
<div class="row">
<div class="col tab-content">
<div class="tab-pane active show" id="subject" role="tabpanel">
<div class="row">
<div class="col-md-12 col-xl-12">
<div class="markdown-body">
<p class="text-muted m-b-15">
</p><h1>My Mouse</h1>
<p>Remember to git add &amp;&amp; git commit &amp;&amp; git push each exercise!</p>
<p>We will execute your function with our test(s), please DO NOT PROVIDE ANY TEST(S) in your file</p>
<p>For each exercise, you will have to create a folder and in this folder, you will have additional files that contain your work. Folder names are provided at the beginning of each exercise under <code>submit directory</code> and specific file names for each exercise are also provided at the beginning of each exercise under <code>submit file(s)</code>.</p>
<hr>
<table>
<thead>
<tr>
<th>My Mouse</th>
<th></th>
</tr>
</thead>
<tbody>
<tr>
<td>Submit directory</td>
<td>.</td>
</tr>
<tr>
<td>Submit files</td>
<td>Makefile - *.c - *.h</td>
</tr>
</tbody>
</table>
<h3>Description</h3>
<img src="https://storage.googleapis.com/qwasar-public/s02_SE/my_mouse_maze.jpg" width="400">
<p>Walk in a labyrinth :
◦ This project is about finding the shortest path between entering and leaving
a labyrinth while avoiding obstacles.
◦ A maze is given to you in a file to be passed as an argument to the program
(Maze generator in Appendix).
◦ The first line of the labyrinth contains the information to read the map:
∗ The number of labyrinth lines then the number of columns (LINExCOL);
∗ The "full" character
∗ The "empty" character
∗ The character "path"
∗ The character "entered labyrinth"
∗ The character "exit labyrinth".
◦ The maze is composed of "empty" characters, "full" characters, characters "entering the labyrinth" and characters "exiting the labyrinth".
◦ The purpose of the program is to replace "empty" characters with "path" characters to represent the shortest way to cross the labyrinth.
◦ Movements can only be horizontally or vertically, not diagonally.
◦ In the case where several solutions exist, one will choose to represent the shortest one. In case of equality, it will be the one whose exit where the solution is the most up then the leftmost. If there are 2 solutions for the same output, when crossing from the start we will choose the solutions in this order: up&gt; left&gt; right&gt; down
So if you have a choice between going up or right, you have to take the solution
that goes up.</p>
<p>◦ Definition of a valid map :
∗ All lines must respect the sizes given in the first line (LINExCOL).
∗ There can only be one entrance.
∗ There must be only one exit.
∗ There must be a solution to the labyrinth.
∗ The labyrinth will not be more than a thousand square.
∗ At the end of each line, there is a new line.
∗ The characters present in the map must be only those shown on the first
line.
∗ If there is an invalid map, you will print MAP ERROR on STDERR followed by a new line. The program will then proceed to the next labyrinth
treatment.</p>
<ul>
<li>Exit(s) will always be located on "outside walls"</li>
</ul>
<p><strong>Example 00</strong></p>
<pre class=" language-plain"><code class=" language-plain">$&gt;cat -e 01.map
10x10* o12$
***1******$
*       **$
* *  **  *$
*        *$
** ** ** *$
*       **$
*      ***$
**       *$
*        *$
***2******$
$&gt;./my_mouse 01.map
10x10* o12
***1******
*  o    **
* *o **  *
* oo     *
**o** ** *
* oo    **
*  o   ***
** o     *
*  o     *
***2******
10 STEPS!
</code></pre>
<p><strong>Example 01</strong></p>
<pre class=" language-plain"><code class=" language-plain">$&gt;cat -e 02.map
10x10* o12$
**1*******$
*      * *$
*  *   ***$
*    *   *$
*   *    *$
*        *$
* *      *$
*     *  *$
***    ***$
****2*****$
$&gt;./my_mouse 02.map
10x10* o12
**1*******
* o    * *
* o*   ***
* oo   * *
*  o*    *
*  oo    *
* * o    *
*   o  * *
*** o  ***
****2*****
10 STEPS
</code></pre>
<p><strong>Example 02</strong></p>
<pre class=" language-plain"><code class=" language-plain">$&gt;./my_mouse bug.map
MAP ERROR
$&gt;
</code></pre>
<p><div><a href="https://storage.googleapis.com/qwasar-public/s02_SE/01.map" target="_blank">01.map</a></div>
<div><a href="https://storage.googleapis.com/qwasar-public/s02_SE/02.map" target="_blank">02.map</a></div>
<div><a href="https://storage.googleapis.com/qwasar-public/s02_SE/03.map" target="_blank">03.map</a></p></div>
<p><strong>Tips</strong>
To generate maps:</p>
<pre class=" language-plain"><code class=" language-plain">#!/usr/bin/env ruby
if ARGV.count &lt; 3 || ARGV[2].length &lt; 5
	puts "./usage height width characters"
else
	height, width, chars, gates = ARGV[0].to_i, ARGV[1].to_i, ARGV[2], ARGV[3].to_i
	entry = rand(width - 4) + 2
	entry2 = rand(width - 4) + 2
#	exit2 = rand(width - 4) + 2
	puts("#{height}x#{width}#{ARGV[2]}")
	height.times do |y|
		width.times do |x|
			if y == 0 &amp;&amp; x == entry
				print chars[3].chr
			elsif y == height - 1 &amp;&amp; x == entry2
				print chars[4].chr
			elsif y.between?(1, height - 2) &amp;&amp; x.between?(1, width - 2) &amp;&amp; rand(100) &gt; 20
				print chars[1].chr
#			elsif y == exit2 &amp;&amp; x == width - 1
#				print chars[4].chr
			else
				print chars[0].chr
			end
		end
		puts
	end
end
</code></pre>
<pre class=" language-plain"><code class=" language-plain">ruby maze_generator.rb 10 10 "* o12"
</code></pre>
<pre class=" language-plain"><code class=" language-plain">class MouseResolver
    attr_accessor :data
    attr_accessor :header_line
    attr_accessor :last_line
    attr_accessor :map_height, :map_width
    attr_accessor :chars

    def initialize
        self.data = []
        self.chars = ""
        self.map_height = 0
        self.map_width = 0
    end

    def load(data)
        index = 0

        data.each do |line|
            if index == 0
                self.setHeaderLine(line)
            elsif index &lt;= self.map_height
                self.data &lt;&lt; line
            else
                self.setLastLine(line)
            end
            index += 1
        end
    end

    def setHeaderLine(header_line)
        @header_line    = header_line
        self.map_height = header_line.to_i
        x_pos = header_line.index('x')
        raise "Invalid header, expected HEIGHTxWIDTH* o12 got #{header_line}" if x_pos == nil
        self.map_width  = header_line[x_pos+1..-1].to_i
        self.chars = header_line[(self.map_height.to_s.size + self.map_width.to_s.size) + 1..-1].strip
    end

    def setLastLine(last_line)
        @last_line = last_line
    end

    def print
        p self.map_height
        p self.map_width
        p self.data
        p self.chars
    end

    def print_map
        self.data.each do |line|
            puts line
        end
    end

    def _find_entrance
        y = 0
        x = 0
        while y &lt; self.data.size
            while x &lt; self.data[y].size
                if self.data[y][x] == '1'
                    return [y, x]
                end
                x += 1
            end
            y += 1
        end
        [-1, -1]
    end

    def _where_to(y, x)
        [[y - 1, x], [y, x - 1], [y, x + 1], [y + 1, x]].each do |future_y, future_x|
            next if future_y &lt; 0 or future_x &lt; 0
            next if future_y &gt; self.map_height
            next if future_x &gt; self.map_width

            if [self.chars[2], self.chars[4]].include?(self.data[future_y][future_x])
                return [future_y, future_x]
            end
        end
        [-1, -1]
    end

    def resolve
        y, x = _find_entrance
        step = 0

        loop do
            self.print_map
            if self.data[y][x] == self.chars[4]
                return step
            end
            if y == -1 or x == -1
                break
            end
            self.data[y][x] = '+'
            y, x = _where_to(y, x)
            step += 1
        end
        -1
    end


    def self.resolve(str_map)
      mr = MouseResolver.new
      mr.load(str_map.split("
"))
      nbr_step = mr.resolve
      raise 'Exit not reached, invalid solution' if nbr_step == -1
      nbr_step
    end
end

def get_argf
    data = []
    ARGF.each do |line|
        data &lt;&lt; line.strip
    end
    data
end

data = get_argf

p MouseResolver.resolve(data.join("\n"))
</code></pre>
<pre class=" language-plain"><code class=" language-plain">./my_mouse 01.map | ruby my_mouse_checker
</code></pre>

<p></p>
</div>

</div>
</div>
</div>
<div class="tab-pane" id="resources" role="tabpanel">
</div>
</div>
</div>
</div>
