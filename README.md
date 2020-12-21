<h1>Codam Coding College Project: libasm</h1>
<p>libasm (2019) Codam Coding College, an intro project to the assembly language.</p>
<h2>Using the project</h2>
<p>Clone the project with git clone:<br>
<code>git clone [repo_link] [folder_name]</code></p>
<p>Create the library:<br>
<code>make</code></p>
<p>The library will be found under:<br>
<code>libasm.a</code></p>
<p>It can be compiled with C mains and other projects using:<br>
    <code>gcc -Wall -Werror -Wextra main.c -L. -lasm</code> OR <code>gcc -Wall -Werror -Wextra main.c libasm.a</code></p>
<p>A tester main is available using:<br><code>./asm_tester</code></p>
<p>Main is able to test one function at a time, or all of them at once.</p>
<p>Commands:<br><code>all | strlen | read | strcmp | strcpy | strdup | write</code></p>
