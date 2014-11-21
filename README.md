Secure_coding_project
=====================

This project is parser for music library REST API export defined by [here](http://beets.readthedocs.org/en/latest/plugins/web.html#json-api)

Parser uses pushdown automata for parsing almost any valid JSON - expect bool and null values

The resultet JSON tree is then passed to classes which understands semanticaly the JSON forma and
by them is parsed  to concrete forma.
