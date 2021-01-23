/*
 * ScriptEditor.h
 */

#import <AppKit/AppKit.h>
#import <ScriptingBridge/ScriptingBridge.h>


@class ScriptEditorItem, ScriptEditorApplication, ScriptEditorColor, ScriptEditorDocument, ScriptEditorWindow, ScriptEditorAttributeRun, ScriptEditorCharacter, ScriptEditorParagraph, ScriptEditorText, ScriptEditorAttachment, ScriptEditorWord, ScriptEditorObjectClass, ScriptEditorInsertionPoint, ScriptEditorLanguage, ScriptEditorSelectionObject, ScriptEditorPrintSettings;

enum ScriptEditorSavo {
	ScriptEditorSavoAsk = 'ask ' /* Ask the user whether or not to save the file. */,
	ScriptEditorSavoNo = 'no  ' /* Do not save the file. */,
	ScriptEditorSavoYes = 'yes ' /* Save the file. */
};
typedef enum ScriptEditorSavo ScriptEditorSavo;

enum ScriptEditorEnum {
	ScriptEditorEnumStandard = 'lwst' /* Standard PostScript error handling */,
	ScriptEditorEnumDetailed = 'lwdt' /* print a detailed report of PostScript errors */
};
typedef enum ScriptEditorEnum ScriptEditorEnum;

@protocol ScriptEditorGenericMethods

- (void) closeSaving:(ScriptEditorSavo)saving savingIn:(NSURL *)savingIn;  // Close an object.
- (void) delete;  // Delete an object.
- (void) duplicateTo:(SBObject *)to withProperties:(NSDictionary *)withProperties;  // Copy object(s) and put the copies at a new location.
- (BOOL) exists;  // Verify if an object exists.
- (void) moveTo:(SBObject *)to;  // Move object(s) to a new location.
- (void) saveAs:(NSString *)as in:(NSURL *)in_;  // Save an object.
- (void) checkSyntax;  // Check the syntax of a document.
- (BOOL) compile;  // Compile the script of a document.
- (void) saveAs:(NSString *)as in:(NSURL *)in_ runOnly:(BOOL)runOnly startupScreen:(BOOL)startupScreen stayOpen:(BOOL)stayOpen;  // Save an object.

@end



/*
 * Standard Suite
 */

// A scriptable object.
@interface ScriptEditorItem : SBObject <ScriptEditorGenericMethods>

@property (copy) NSDictionary *properties;  // All of the object's properties.


@end

// An application's top level scripting object.
@interface ScriptEditorApplication : SBApplication

- (SBElementArray<ScriptEditorDocument *> *) documents;
- (SBElementArray<ScriptEditorWindow *> *) windows;

@property (readonly) BOOL frontmost;  // Is this the frontmost (active) application?
@property (copy, readonly) NSString *name;  // The name of the application.
@property (copy, readonly) NSString *version;  // The version of the application.

- (ScriptEditorDocument *) open:(NSURL *)x;  // Open an object.
- (void) print:(NSURL *)x printDialog:(BOOL)printDialog withProperties:(ScriptEditorPrintSettings *)withProperties;  // Print an object.
- (void) quitSaving:(ScriptEditorSavo)saving;  // Quit an application.

@end

// A color.
@interface ScriptEditorColor : ScriptEditorItem


@end

// A document.
@interface ScriptEditorDocument : ScriptEditorItem

@property (readonly) BOOL modified;  // Has the document been modified since the last save?
@property (copy) NSString *name;  // The document's name.
@property (copy) NSString *path;  // The document's path.


@end

// A window.
@interface ScriptEditorWindow : ScriptEditorItem

@property NSRect bounds;  // The bounding rectangle of the window.
@property (readonly) BOOL closeable;  // Whether the window has a close box.
@property (copy, readonly) ScriptEditorDocument *document;  // The document whose contents are being displayed in the window.
@property (readonly) BOOL floating;  // Whether the window floats.
- (NSInteger) id;  // The unique identifier of the window.
@property NSInteger index;  // The index of the window, ordered front to back.
@property (readonly) BOOL miniaturizable;  // Whether the window can be miniaturized.
@property BOOL miniaturized;  // Whether the window is currently miniaturized.
@property (readonly) BOOL modal;  // Whether the window is the application's current modal window.
@property (copy) NSString *name;  // The full title of the window.
@property (readonly) BOOL resizable;  // Whether the window can be resized.
@property (readonly) BOOL titled;  // Whether the window has a title bar.
@property BOOL visible;  // Whether the window is currently visible.
@property (readonly) BOOL zoomable;  // Whether the window can be zoomed.
@property BOOL zoomed;  // Whether the window is currently zoomed.


@end



/*
 * Text Suite
 */

// This subdivides the text into chunks that all have the same attributes.
@interface ScriptEditorAttributeRun : ScriptEditorItem

- (SBElementArray<ScriptEditorAttachment *> *) attachments;
- (SBElementArray<ScriptEditorAttributeRun *> *) attributeRuns;
- (SBElementArray<ScriptEditorCharacter *> *) characters;
- (SBElementArray<ScriptEditorParagraph *> *) paragraphs;
- (SBElementArray<ScriptEditorWord *> *) words;

@property (copy) NSColor *color;  // The color of the first character.
@property (copy) NSString *font;  // The name of the font of the first character.
@property NSInteger size;  // The size in points of the first character.


@end

// This subdivides the text into characters.
@interface ScriptEditorCharacter : ScriptEditorItem

- (SBElementArray<ScriptEditorAttachment *> *) attachments;
- (SBElementArray<ScriptEditorAttributeRun *> *) attributeRuns;
- (SBElementArray<ScriptEditorCharacter *> *) characters;
- (SBElementArray<ScriptEditorParagraph *> *) paragraphs;
- (SBElementArray<ScriptEditorWord *> *) words;

@property (copy) NSColor *color;  // The color of the first character.
@property (copy) NSString *font;  // The name of the font of the first character.
@property NSInteger size;  // The size in points of the first character.


@end

// This subdivides the text into paragraphs.
@interface ScriptEditorParagraph : ScriptEditorItem

- (SBElementArray<ScriptEditorAttachment *> *) attachments;
- (SBElementArray<ScriptEditorAttributeRun *> *) attributeRuns;
- (SBElementArray<ScriptEditorCharacter *> *) characters;
- (SBElementArray<ScriptEditorParagraph *> *) paragraphs;
- (SBElementArray<ScriptEditorWord *> *) words;

@property (copy) NSColor *color;  // The color of the first character.
@property (copy) NSString *font;  // The name of the font of the first character.
@property NSInteger size;  // The size in points of the first character.


@end

// Rich (styled) text
@interface ScriptEditorText : ScriptEditorItem

- (SBElementArray<ScriptEditorAttachment *> *) attachments;
- (SBElementArray<ScriptEditorAttributeRun *> *) attributeRuns;
- (SBElementArray<ScriptEditorCharacter *> *) characters;
- (SBElementArray<ScriptEditorParagraph *> *) paragraphs;
- (SBElementArray<ScriptEditorWord *> *) words;

@property (copy) NSColor *color;  // The color of the first character.
@property (copy) NSString *font;  // The name of the font of the first character.
@property NSInteger size;  // The size in points of the first character.


@end

// Represents an inline text attachment.  This class is used mainly for make commands.
@interface ScriptEditorAttachment : ScriptEditorText

@property (copy) NSString *fileName;  // The path to the file for the attachment


@end

// This subdivides the text into words.
@interface ScriptEditorWord : ScriptEditorItem

- (SBElementArray<ScriptEditorAttachment *> *) attachments;
- (SBElementArray<ScriptEditorAttributeRun *> *) attributeRuns;
- (SBElementArray<ScriptEditorCharacter *> *) characters;
- (SBElementArray<ScriptEditorParagraph *> *) paragraphs;
- (SBElementArray<ScriptEditorWord *> *) words;

@property (copy) NSColor *color;  // The color of the first character.
@property (copy) NSString *font;  // The name of the font of the first character.
@property NSInteger size;  // The size in points of the first character.


@end



/*
 * Script Editor Suite
 */

// Script Editor's top level scripting object.
@interface ScriptEditorApplication (ScriptEditorSuite)

- (SBElementArray<ScriptEditorObjectClass *> *) objectClasss;
- (SBElementArray<ScriptEditorLanguage *> *) languages;

@property (copy) ScriptEditorSelectionObject *selection;  // The current selection.

@end

// A class
@interface ScriptEditorObjectClass : ScriptEditorItem


@end

// A script document.
@interface ScriptEditorDocument (ScriptEditorSuite)

- (SBElementArray<ScriptEditorWindow *> *) windows;

@property (copy) ScriptEditorText *contents;  // The contents of the document.
@property (copy) ScriptEditorText *objectDescription;  // The description of the document.
@property (copy, readonly) ScriptEditorText *eventLog;  // The event log of the document.
@property (copy) ScriptEditorLanguage *language;  // The scripting language.
@property (copy) ScriptEditorSelectionObject *selection;  // The current selection.
@property (copy) ScriptEditorText *text;  // The text of the document.

@end

// An insertion point between two objects.
@interface ScriptEditorInsertionPoint : ScriptEditorItem

@property (copy) ScriptEditorItem *contents;  // The contents of the insertion point.


@end

// A scripting language.
@interface ScriptEditorLanguage : ScriptEditorItem

@property (copy, readonly) NSString *objectDescription;  // The description
- (NSString *) id;  // The unique id of the language.
@property (copy, readonly) NSString *name;  // The name of the language.
@property (readonly) BOOL supportsCompiling;  // Is the language compilable?
@property (readonly) BOOL supportsRecording;  // Is the language recordable?


@end

// A way to refer to the state of the current selection.
@interface ScriptEditorSelectionObject : ScriptEditorItem

@property (readonly) NSPoint characterRange;  // The range of characters in the selection.
@property (copy) ScriptEditorItem *contents;  // The contents of the selection.


@end

// Rich (styled) text
@interface ScriptEditorText (ScriptEditorSuite)

- (SBElementArray<ScriptEditorAttributeRun *> *) attributeRuns;
- (SBElementArray<ScriptEditorCharacter *> *) characters;
- (SBElementArray<ScriptEditorInsertionPoint *> *) insertionPoints;
- (SBElementArray<ScriptEditorParagraph *> *) paragraphs;
- (SBElementArray<ScriptEditorText *> *) text;
- (SBElementArray<ScriptEditorWord *> *) words;

@property (copy) NSColor *color;  // The color of the first character.
@property (copy) NSString *font;  // The name of the font of the first character.
@property NSInteger size;  // The size in points of the first character.

@end

// A window.
@interface ScriptEditorWindow (ScriptEditorSuite)

@property (copy) NSString *name;  // The full title of the window.

@end



/*
 * Type Definitions
 */

@interface ScriptEditorPrintSettings : SBObject <ScriptEditorGenericMethods>

@property NSInteger copies;  // the number of copies of a document to be printed
@property BOOL collating;  // Should printed copies be collated?
@property NSInteger startingPage;  // the first page of the document to be printed
@property NSInteger endingPage;  // the last page of the document to be printed
@property NSInteger pagesAcross;  // number of logical pages laid across a physical page
@property NSInteger pagesDown;  // number of logical pages laid out down a physical page
@property (copy) NSDate *requestedPrintTime;  // the time at which the desktop printer should print the document
@property ScriptEditorEnum errorHandling;  // how errors are handled
@property (copy) NSString *faxNumber;  // for fax number
@property (copy) NSString *targetPrinter;  // for target printer


@end

