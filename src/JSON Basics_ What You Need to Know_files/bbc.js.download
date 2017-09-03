
function wrapTags ( tagName )
{
  var startTags = new Array;
  var endTags = new Array;

  startTags['b'] = '[b]';
  endTags['b'] = '[/b]';
  startTags['i'] = '[i]';
  endTags['i'] = '[/i]';
  startTags['code'] = '\n[code]\n';
  endTags['code'] = '\n[/code]\n';

  var startTag = startTags[tagName];
  var endTag = endTags[tagName];

  var content = document.getElementById( "content" );
 
  if ( document.selection )
  {
    document.getElementById( "content" ).focus();
    var sel=document.selection.createRange();
    var str=sel.text;
    sel.text=startTag+str+endTag;
  } else if ( typeof content.selectionStart != 'undefined' )
  {
    var startPos = content.selectionStart;
    var endPos = content.selectionEnd;
    var cursorPos = endPos;
    var scrollTop = content.scrollTop;

    var before, after, selection;
    before = content.value.substring( 0, content.selectionStart );
    selection = content.value.substring( content.selectionStart, content.selectionEnd );
    after = content.value.substring( content.selectionEnd, content.value.length );
    content.value = before + startTag + selection + endTag + after;
    content.focus();
    tags = startTag + endTag;

    if ( selection.length ) {
      content.selectionStart = cursorPos + tags.length;
      content.selectionEnd = cursorPos + tags.length;
    } else {
      content.selectionStart = cursorPos + startTag.length;
      content.selectionEnd = cursorPos + startTag.length;
    }

    content.scrollTop = scrollTop;
  }

 
}

