# Chapter 09: Data Serialization

-  The semantic superiority of explicit encoding against ambiguous encodings in databases; the fundamental difference between simple and complex types (schema vs. schemaless).

-  Classic industrial TLV (*Tag-Length-Value*) binary pattern, simplifying the absence of syntactic keys like brackets/braces and avoiding manual byte escaping.

-  Explicit establishment of the numbering list (enum) defining valid data: Null, Int, Double, String, and Array for assembling server Responses.

-  Compact functions based on modular injection of binary packets directly into the vector buffer (`out_nil`, `out_int`, `out_arr`).

-  Retroactive buffer reservation mechanics (saving `header_pos`), which adjusts the total packet size retroactively depending on the indefinite growth of the generated body.