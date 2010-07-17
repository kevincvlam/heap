/**************************************************************
* stuff i copied from huff assignment, for personal reference
**************************************************************/


//1. Takes the name of a file to uncompress as the first command-line argument and the name
//of a file in which to write the uncompressed version.
int main(int argc, char* argv[]) {


// Reads char_freqs.txt and builds a Huffman tree from the frequencies.

    ifstream in ("ta_stats.txt");

// read into string
// find number in the string
// put it in array

    int freq[NUM_CHAR] = {0,0};

// Build a Huffman tree (just like for compression) and use it to decode the compressed
// file, then write the decoded version to another text file.

    HuffHeap heap;
    HuffNode* cur = 0;

    for (i=0; i<NUM_CHAR; i++){
        if (freq[i] != 0){
            cur = new HuffNode((char)i, freq[i], 0, 0);
            heap.insert(cur);
        }
    }

    HuffHeap* root = buildTree(heap);

//Use tree to decode the compressed file, then write the decoded version to another text file.

    vector<bool> sequence;

    BitFileIn in(compressed);
    bool bit;
    while (in.get(bit)) {
        sequence.push_back(bit);
    }
    in.close();

// Using the Huffman tree, uncompresses the message and prints it to standard output.

    ofstream out = uncompressed;
    decode(out, sequence, root, root, 0);
    out.close();

}
