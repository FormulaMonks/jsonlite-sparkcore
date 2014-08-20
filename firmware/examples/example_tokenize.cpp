#include "application.h"
#include "jsonlite/jsonlite.h"

void setup() {
  const int JSON_DEPTH = 4;                                                   // Limitation of JSON depth
  char json[] = "[-1, 0, 1, true, false, null]";                              // JSON to validate
  size_t mem_used = jsonlite_parser_estimate_size(JSON_DEPTH);                // Estimate memory usage
  printf("jsonlite will use %zd bytes of RAM for JSON validation", mem_used);
  jsonlite_parser p = jsonlite_parser_init(JSON_DEPTH);                       // Init parser with specified depth
  jsonlite_result result = jsonlite_parser_tokenize(p, json, sizeof(json));   // Check JSON
  // Check result
  if (result == jsonlite_result_ok) {
    // do stuff
  }
  jsonlite_parser_release(p);
}

void loop() {

}