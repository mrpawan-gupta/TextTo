# Text Similarity : Cosine Similarity

The purpose of this example is to get familiarize with *Text Processing & Information Retrieval* By :
- Calculing *Term Frequency*,
- *Tokenizing Vectors*,
- Calculating *Cosine Similarity*,
- and, *Vecort Product*.

In this Project, we'll:
- Read two lines of text from two files, and
- Tokenize them;
- Read a list of [stop words](https://en.wikipedia.org/wiki/Stop_words) from another file, and
- Filter them out;
- Compute the [cosine similarity](https://en.wikipedia.org/wiki/Cosine_similarity) of the two lines of text (using frequencies), and
- Write the result into a file.

*Cosine Similarity* is defined as vector similarity in terms of the angle separating two vectors.
It is calculated by Dot product of vectors. to get similarity ranging from -1 to 1 where
- 1 is Exact match
- -1 is Exact Unmatched
- 0 is Unmatched 

<div class="equation" align="center" data-raw-text="s(\mathbf{x},\mathbf{y}) = {\mathbf{x} \cdot \mathbf{y} \over \|\mathbf{x}\| \|\mathbf{y}\|} = \frac{ \sum\limits_{i=0}^{n-1}{x_i y_i} }{ \sqrt{\sum\limits_{i=0}^{n-1}{(x_i)^2}} \times \sqrt{\sum\limits_{i=0}^{n-1}{(y_i)^2}} }" data-equation="eq:cosine_similarity">
	<img src="https://cdn.rawgit.com/compute-io/cosine-similarity/bdef940bf4e6d320d2652b52f54f58cf2ea5d794/docs/img/eqn_similarity.svg" alt="Cosine similarity formula">
	<br>
</div>